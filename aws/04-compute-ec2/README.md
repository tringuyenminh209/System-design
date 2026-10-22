# Module 04: Máy chủ tính toán EC2 & Tự động cấu hình UserData

Bài học này giúp bạn triển khai một máy chủ EC2 hoàn chỉnh và giải quyết vấn đề lớn nhất của người mới học CloudFormation: **Tránh hardcode AMI ID**.

---

## 1. Mẹo chuyên nghiệp: Tự động lấy AMI ID bằng SSM Parameter

Trong quá khứ, mỗi lần đổi Region bạn phải tra cứu AMI ID tương ứng và dùng `Mappings`.
Hiện nay, AWS hỗ trợ lấy trực tiếp AMI Linux mới nhất thông qua SSM:
```yaml
LatestAmiId:
  Type: 'AWS::SSM::Parameter::Value<AWS::EC2::Image::Id>'
  Default: '/aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-x86_64'
```
👉 Bạn có thể deploy template này ở Tokyo (`ap-northeast-1`), Singapore (`ap-southeast-1`) hay Mỹ (`us-east-1`) mà **không bao giờ bị lỗi sai AMI ID**!

---

## 2. Kỹ thuật viết UserData trong CloudFormation

UserData cần được mã hóa Base64:
```yaml
UserData:
  Fn::Base64: !Sub |
    #!/bin/bash
    dnf update -y
    dnf install -y httpd
```
- Dấu gạch đứng `|` cho phép viết script nhiều dòng tự nhiên.
- `!Sub`: Cho phép chèn các biến như `${EnvironmentName}` trực tiếp vào trong script bash!
- Lấy thông tin máy chủ bằng **IMDSv2 (Instance Metadata Service v2)** thông qua Token: bảo mật cao, chống các cuộc tấn công SSRF.
