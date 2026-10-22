# Module 06: Cơ sở dữ liệu RDS & Lưu trữ chia sẻ EFS

Dữ liệu là phần quan trọng nhất của mọi ứng dụng. Bài học này tập trung vào 2 dịch vụ lưu trữ cốt lõi:
1. **Amazon RDS (Relational Database Service - MySQL/PostgreSQL)**
2. **Amazon EFS (Elastic File System)**

---

## 1. Lưu ý quan trọng khi cấu hình RDS bằng CloudFormation
- **DBSubnetGroup:** RDS bắt buộc phải có ít nhất 2 Subnet ở 2 Availability Zones khác nhau, ngay cả khi bạn chạy Single-AZ (để sẵn sàng failover khi bật Multi-AZ).
- **`NoEcho: true`:** Luôn thêm thuộc tính này cho tham số mật khẩu (`DBPassword`) để CloudFormation che dấu giá trị, không in ra màn hình hoặc log.
- **`DeletionPolicy: Snapshot`:** Trong trường hợp lỡ tay xóa Stack, AWS sẽ tự động chụp lại một bản Final DB Snapshot trước khi hủy instance, giúp khôi phục dữ liệu bất kỳ lúc nào.

---

## 2. EFS vs EBS vs S3

| Đặc điểm | EBS | EFS | S3 |
|:---|:---|:---|:---|
| **Giao thức** | Block Storage (ổ đĩa cứng) | File Storage (NFSv4) | Object Storage (HTTP/REST) |
| **Gắn nhiều máy** | Chỉ 1 EC2 (trừ Multi-Attach io2) | Hàng nghìn EC2 cùng lúc | Không giới hạn qua API |
| **Phạm vi** | Cố định trong 1 AZ | Multi-AZ (toàn VPC) | Toàn Region |
| **Trường hợp dùng** | Hệ điều hành (OS), Database | Upload thư mục CMS (WordPress, Laravel) | Ảnh tĩnh, Video, Backup |
