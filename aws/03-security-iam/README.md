# Module 03: Bảo mật IAM & Security Groups phân tầng

Bài học này giải quyết 2 bài toán bảo mật sống còn của kiến trúc đám mây:
1. **Phân tầng Security Groups (Defense in Depth)**
2. **Cấp quyền cho máy chủ không dùng Access Key (IAM Role + Instance Profile)**

---

## 1. Nguyên lý Security Group lồng nhau (`SourceSecurityGroupId`)

Thay vì mở cổng cho dải IP (`CidrIp: 0.0.0.0/0` hoặc `CidrIp: 10.0.0.0/16`), bạn sử dụng:
```yaml
SecurityGroupIngress:
  - IpProtocol: tcp
    FromPort: 80
    ToPort: 80
    SourceSecurityGroupId: !Ref ALBSecurityGroup
```
👉 **Lợi ích:** Kể cả khi kẻ tấn công biết IP nội bộ của EC2, họ cũng không thể gửi request đến EC2. Traffic bắt buộc phải đi qua Load Balancer (nơi đã có kiểm tra SSL/WAF) thì mới được chấp nhận.

---

## 2. Vì sao phải dùng Instance Profile?

Trong CloudFormation:
- `AWS::IAM::Role` là đối tượng chứa các quyền (Policy).
- `AWS::IAM::InstanceProfile` là đối tượng bọc ngoài để gắn Role đó vào máy chủ `AWS::EC2::Instance`.
- Khi máy chủ EC2 có gắn Instance Profile với `AmazonSSMManagedInstanceCore`, bạn có thể dùng **AWS Systems Manager Session Manager** để mở terminal trực tiếp trên web console mà **không cần mở cổng SSH 22** ra ngoài internet!
