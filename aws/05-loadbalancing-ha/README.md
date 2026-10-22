# Module 05: Cân bằng tải (ALB) & Tự động co giãn (Auto Scaling Group)

Đây là cốt lõi của tính sẵn sàng cao (**High Availability - HA**) và khả năng chịu lỗi (**Fault Tolerance**) trên AWS.

---

## 1. Mối liên hệ giữa ALB, Target Group và ASG

```
User Request (Port 80/443)
       │
       ▼
[ Application Load Balancer ] (Nằm trong Public Subnets)
       │ (Listener forwards traffic)
       ▼
[ Target Group ] (Health Check: GET /)
       ▲
       │ Tự động đăng ký (Register) IP của các Instance
       ▼
[ Auto Scaling Group ] (Nằm trong Private Subnets, Multi-AZ)
 ├── EC2 Instance 1 (AZ-a)
 └── EC2 Instance 2 (AZ-c)
```

1. **Launch Template:** Thay thế hoàn toàn Launch Configuration cũ, lưu trữ AMI, UserData và cấu hình phần cứng của Instance.
2. **HealthCheckType: ELB:** Auto Scaling Group sẽ hỏi ALB xem máy chủ có phản hồi mã HTTP 200 không. Nếu máy chủ bị treo ứng dụng (kể cả phần cứng EC2 vẫn chạy), ASG sẽ tự động hủy (terminate) máy chủ lỗi và tạo một máy chủ mới thay thế!
3. **PropagateAtLaunch: true:** Đảm bảo mọi máy chủ mới sinh ra từ ASG đều tự động được gắn Tag của môi trường.
