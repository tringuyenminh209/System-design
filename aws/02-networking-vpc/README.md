# Module 02: Thiết kế mạng VPC Multi-AZ chuẩn Production

Hạ tầng mạng là xương sống của mọi hệ thống trên AWS. Bài học này hướng dẫn bạn cách viết template tạo một **VPC hoàn chỉnh trên 2 Availability Zones (Multi-AZ)** phục vụ High Availability.

---

## 1. Kiến trúc phân tầng mạng (Network Architecture)

```
[ Internet ]
     |
[ Internet Gateway ]
     |
+---------------------------------------------------------------+
| VPC (10.0.0.0/16)                                            |
|                                                               |
|   +-----------------------+       +-----------------------+   |
|   | Public Subnet 1 (AZ a)|       | Public Subnet 2 (AZ c)|   |
|   | 10.0.1.0/24           |       | 10.0.2.0/24           |   |
|   | [NAT Gateway]         |       | [ALB Listener]        |   |
|   +-----------------------+       +-----------------------+   |
|               |                                               |
|   +-----------------------+       +-----------------------+   |
|   | Private Subnet 1(AZ a)|       | Private Subnet 2(AZ c)|   |
|   | 10.0.11.0/24          |       | 10.0.12.0/24          |   |
|   | [App / EC2 Instances] |       | [RDS Database]        |   |
|   +-----------------------+       +-----------------------+   |
+---------------------------------------------------------------+
```

---

## 2. Kỹ thuật quan trọng cần ghi nhớ
1. **`!GetAZs ''`:** Trả về danh sách tất cả các Availability Zones của Region hiện tại (ví dụ: `[ap-northeast-1a, ap-northeast-1c, ap-northeast-1d]`). Dùng `!Select [0, !GetAZs '']` giúp template tự động chạy được trên bất kỳ Region nào mà không bị gán cứng (hardcode) tên AZ!
2. **DependsOn:** Dùng để kiểm soát thứ tự khởi tạo. Ví dụ: `NatGatewayEIP` cần `DependsOn: InternetGatewayAttachment` vì Elastic IP trong VPC cần Internet Gateway gắn vào VPC trước.
3. **Cross-Stack Exports:** Khối `Outputs` sử dụng `Export: Name:` để xuất `VpcId`, `PublicSubnets`, `PrivateSubnets`. Khi viết các Stack cho EC2 hoặc Database ở các bài sau, bạn chỉ cần dùng `!ImportValue dev-VpcId` mà không cần nhập lại ID bằng tay.
