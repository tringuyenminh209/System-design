# Module 07: Dự án thực chiến — Kiến trúc Web 3 tầng (3-Tier Production Architecture)

Đây là **dự án mẫu hoàn chỉnh (Capstone Project)** giúp bạn làm chủ cách thiết kế và triển khai một hạ tầng chuẩn doanh nghiệp trên AWS hoàn toàn bằng **Infrastructure as Code (AWS CloudFormation)**.

---

## 1. Sơ đồ kiến trúc tổng thể (3-Tier Architecture)

```
[ Người dùng Internet ]
         │ (HTTP :80 / HTTPS :443)
         ▼
[ Internet Gateway ]
         │
====================================== TIER 1: PRESENTATION LAYER ======================================
  [ Application Load Balancer ] (Public Subnet 1a & 1c) ── Gán ALBSecurityGroup
         │
         │ (Forward HTTP :80 nội bộ)
         ▼
====================================== TIER 2: APPLICATION LAYER =======================================
  [ Auto Scaling Group ] (Private Subnet 1a & 1c) ────── Gán AppSecurityGroup (Chỉ nhận từ ALB SG)
    ├── EC2 Web/App Instance 1 (AZ-a)
    └── EC2 Web/App Instance 2 (AZ-c)
         │
         │ (MySQL Query Port :3306)
         ▼
====================================== TIER 3: DATA / DATABASE LAYER ===================================
  [ Amazon RDS MySQL Multi-AZ ] (Data Subnet 1a & 1c) ── Gán DatabaseSecurityGroup (Chỉ nhận từ App SG)
    ├── Master DB Instance (Active - AZ-a)
    └── Standby DB Instance (Synchronous Replica - AZ-c)
```

---

## 2. Các điểm đắt giá trong thiết kế này:

1. **Bảo mật tuyệt đối (Zero Trust trong VPC):**
   - Tầng Web/App và Database nằm hoàn toàn trong **Private Subnets**. Không một hacker nào có thể scan hoặc truy cập trực tiếp IP của EC2 hay RDS từ Internet.
   - Database chỉ chấp nhận kết nối từ `AppSecurityGroup`.
2. **Khả năng tự phục hồi (Self-Healing & Auto-Recovery):**
   - Nếu 1 Availability Zone của AWS gặp sự cố mất điện, ALB tự động điều hướng 100% traffic sang AZ còn lại.
   - RDS Multi-AZ tự động chuyển quyền (failover) sang bản Standby chỉ trong vòng 60-120 giây mà không cần can thiệp thủ công.
3. **Triển khai 1-Click bằng CloudFormation:**
   - Toàn bộ hơn 20 tài nguyên AWS (VPC, 6 Subnets, IGW, NAT Gateway, 3 Route Tables, 3 Security Groups, ALB, Target Group, Listener, Launch Template, Auto Scaling Group, RDS Multi-AZ, S3 Bucket) được khởi tạo tự động chỉ bằng **1 lệnh duy nhất**.

---

## 3. Lệnh triển khai dự án lên AWS

```bash
# Kiểm tra tính hợp lệ của template
aws cloudformation validate-template --template-body file://10-full-3tier-architecture.yml

# Triển khai hệ thống lên AWS (khu vực Tokyo ap-northeast-1 hoặc tuỳ chọn)
aws cloudformation create-stack \
  --stack-name production-3tier-app \
  --template-body file://10-full-3tier-architecture.yml \
  --parameters ParameterKey=EnvironmentName,ParameterValue=prod \
               ParameterKey=DBPassword,ParameterValue=MySecurePassword2026! \
  --capabilities CAPABILITY_IAM \
  --region ap-northeast-1

# Lấy URL website sau khi triển khai xong
aws cloudformation describe-stacks \
  --stack-name production-3tier-app \
  --query "Stacks[0].Outputs[?OutputKey=='WebsiteURL'].OutputValue" \
  --output text
```
