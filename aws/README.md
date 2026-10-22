# Lộ trình Học AWS CloudFormation — Infrastructure as Code (IaC)

Tài liệu và bộ mẫu template thực hành này được xây dựng dành cho bạn đã có kiến thức nền tảng về AWS (EC2, VPC, S3, RDS, IAM,...) và muốn **nâng cấp kỹ năng chuyên sâu vào việc lập trình hạ tầng tự động bằng mã nguồn (Infrastructure as Code - IaC) với AWS CloudFormation**.

---

## Mục lục lộ trình học tập

| Module | Tên học phần | Nội dung trọng tâm | Template mẫu |
|:---:|:---|:---|:---|
| **01** | [Cơ bản về CloudFormation](01-fundamentals/README.md) | Cú pháp YAML, các khối cấu trúc, hàm nội tại (`!Ref`, `!Sub`, `!GetAtt`) | `01-s3-bucket.yml` |
| **02** | [Mạng VPC & Phân vùng Subnet](02-networking-vpc/README.md) | Thiết kế VPC chuẩn Multi-AZ, Public/Private Subnet, Internet Gateway, NAT Gateway | `02-vpc-subnets.yml` |
| **03** | [Bảo mật IAM & Security Groups](03-security-iam/README.md) | Security Groups phân tầng an toàn, IAM Role và Instance Profile cho EC2 | `03-security-groups.yml`<br>`04-iam-roles.yml` |
| **04** | [Tính toán máy chủ EC2](04-compute-ec2/README.md) | Khởi tạo EC2, UserData tự động cài đặt Web Server, gắn Elastic IP | `05-ec2-webserver.yml` |
| **05** | [Cân bằng tải & Tự co giãn](05-loadbalancing-ha/README.md) | Application Load Balancer (ALB), Target Group, Auto Scaling Group (ASG), Launch Template | `06-alb.yml`<br>`07-asg.yml` |
| **06** | [Lưu trữ & Database (RDS/EFS)](06-database-storage/README.md) | RDS MySQL/PostgreSQL Multi-AZ cô lập trong Private Subnet, EFS Storage | `08-rds-mysql.yml`<br>`09-efs.yml` |
| **07** | [Dự án 3-Tier Production](07-production-3tier-project/README.md) | Dự án tổng hợp: Triển khai toàn bộ hệ thống Web 3 tầng chuẩn doanh nghiệp | `10-full-3tier-architecture.yml` |

---

## 1. Cấu trúc chuẩn của một tệp CloudFormation Template

Mọi template CloudFormation (định dạng YAML) đều tuân theo khung sườn chuẩn sau:

```yaml
AWSTemplateFormatVersion: '2010-09-09' # Phiên bản cú pháp bắt buộc
Description: >
  Mô tả mục đích của template này.

# 1. Tham số đầu vào: Cho phép tùy biến giá trị khi tạo Stack
Parameters:
  EnvironmentName:
    Type: String
    Default: dev
    AllowedValues: [dev, staging, prod]
    Description: Môi trường triển khai

# 2. Bảng ánh xạ: Giống switch-case hoặc dictionary tĩnh
Mappings:
  RegionMap:
    ap-northeast-1: # Tokyo
      AMI: ami-0d52744d6551d851e
    us-east-1:      # N. Virginia
      AMI: ami-0c7217cdde317cfec

# 3. Điều kiện: Tạo tài nguyên dựa trên tham số (true/false)
Conditions:
  IsProduction: !Equals [!Ref EnvironmentName, prod]

# 4. Tài nguyên (BẮT BUỘC): Định nghĩa các thành phần AWS cần tạo
Resources:
  MyS3Bucket:
    Type: AWS::S3::Bucket
    Properties:
      BucketName: !Sub "${EnvironmentName}-my-app-storage-${AWS::AccountId}"

# 5. Giá trị đầu ra: Hiển thị thông tin hoặc xuất cho Stack khác dùng
Outputs:
  BucketARN:
    Description: ARN của S3 Bucket vừa tạo
    Value: !GetAtt MyS3Bucket.Arn
    Export:
      Name: !Sub "${EnvironmentName}-BucketARN"
```

---

## 2. Các hàm nội tại (Intrinsic Functions) phải nhớ

Trong CloudFormation, bạn không gọi hàm thông thường mà dùng các thẻ nội tại:

| Hàm cú pháp ngắn | Ý nghĩa | Ví dụ áp dụng |
|:---|:---|:---|
| `!Ref` | Lấy giá trị tham số (Parameter) hoặc ID của tài nguyên (Resource ID) | `VpcId: !Ref MyVPC` |
| `!GetAtt` | Lấy thuộc tính cụ thể của tài nguyên (như DNSName, ARN, PrivateIp) | `TargetArn: !GetAtt MyALB.DNSName` |
| `!Sub` | Thay thế chuỗi (String Interpolation) bằng biến hoặc pseudo-parameter | `!Sub "${Environment}-server-${AWS::Region}"` |
| `!Join` | Nối danh sách các chuỗi lại với nhau bằng ký tự phân cách | `!Join [",", [!Ref Subnet1, !Ref Subnet2]]` |
| `!FindInMap` | Tra cứu giá trị trong khối `Mappings` theo 2 khóa cấp 1 và cấp 2 | `ImageId: !FindInMap [RegionMap, !Ref "AWS::Region", AMI]` |
| `!Select` | Chọn phần tử thứ `n` trong danh sách (danh sách đánh số từ 0) | `!Select [0, !Ref SubnetList]` |
| `!ImportValue` | Lấy giá trị được Export từ một CloudFormation Stack khác | `VpcId: !ImportValue dev-VpcId` |

---

## 3. Các Pseudo Parameters do AWS tự cung cấp

Bạn có thể gọi trực tiếp bất kỳ lúc nào mà không cần khai báo trong `Parameters`:
- `AWS::Region`: Tên khu vực hiện tại (ví dụ: `ap-northeast-1`).
- `AWS::AccountId`: ID tài khoản AWS của bạn (ví dụ: `123456789012`).
- `AWS::StackName`: Tên của Stack đang chạy.
- `AWS::NoValue`: Giá trị rỗng (dùng trong Conditions để bỏ qua một thuộc tính).

---

## 4. Cách triển khai Template lên AWS

### Cách 1: Sử dụng giao diện AWS Console
1. Đăng nhập vào AWS Console, tìm dịch vụ **CloudFormation**.
2. Chọn **Create stack** -> **With new resources (standard)**.
3. Ở mục *Template source*, chọn **Upload a template file** và chọn file `.yml` bạn muốn triển khai.
4. Đặt tên Stack, điền các tham số trong form và bấm **Next** -> **Submit**.
5. Theo dõi tab **Events** để xem quá trình khởi tạo từng tài nguyên theo thời gian thực.

### Cách 2: Sử dụng AWS CLI (Khuyên dùng khi làm việc chuyên nghiệp)
```bash
# Kiểm tra cú pháp template trước khi chạy (Validation)
aws cloudformation validate-template --template-body file://02-networking-vpc/02-vpc-subnets.yml

# Triển khai tạo Stack
aws cloudformation create-stack \
  --stack-name my-dev-vpc \
  --template-body file://02-networking-vpc/02-vpc-subnets.yml \
  --parameters ParameterKey=EnvironmentName,ParameterValue=dev \
  --capabilities CAPABILITY_NAMED_IAM

# Xem trạng thái quá trình tạo
aws cloudformation describe-stacks --stack-name my-dev-vpc --query "Stacks[0].StackStatus"
```
