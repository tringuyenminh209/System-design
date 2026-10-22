# Module 01: CloudFormation Fundamentals

Bài học này giúp bạn làm quen với cấu trúc cú pháp cơ bản nhất của CloudFormation thông qua việc tạo một **S3 Bucket đạt chuẩn bảo mật doanh nghiệp**.

---

## 1. Các khái niệm cốt lõi trong bài
- **Parameters (Tham số đầu vào):** Cho phép truyền giá trị động khi tạo Stack mà không cần sửa code YAML.
- **Conditions (Điều kiện logic):** Dùng `!If [ConditionName, ValueIfTrue, ValueIfFalse]` để bật/tắt tính năng linh hoạt.
- **DeletionPolicy (Chính sách xóa):** Mặc định khi xóa Stack, các tài nguyên sẽ bị xóa theo. Thuộc tính `DeletionPolicy: Retain` giúp bảo vệ các tài nguyên quan trọng (như S3 chứa dữ liệu, Database) không bị xóa nhầm.
- **Mã hóa SSE-S3 & Public Access Block:** Luôn cấu hình mã hóa mặc định `AES256` và chặn mọi truy cập public từ bên ngoài.

---

## 2. Giải thích chi tiết Template `01-s3-bucket.yml`

```yaml
# Đặt tên Bucket duy nhất trên toàn cầu bằng !Sub
BucketName: !Sub "${BucketPrefix}-${EnvironmentName}-${AWS::AccountId}-${AWS::Region}"
```
- `${AWS::AccountId}`: Pseudo-parameter tự lấy số Account AWS hiện tại.
- `${AWS::Region}`: Pseudo-parameter tự lấy Region hiện tại (ví dụ `ap-northeast-1`).
- Nhờ ghép các biến này, bạn sẽ không bao giờ bị lỗi trùng tên Bucket trên AWS (`BucketAlreadyExists`).

---

## 3. Cách chạy thử nghiệm

```bash
# Tạo stack trên AWS
aws cloudformation create-stack \
  --stack-name my-first-s3-stack \
  --template-body file://01-s3-bucket.yml \
  --parameters ParameterKey=EnvironmentName,ParameterValue=dev \
               ParameterKey=BucketPrefix,ParameterValue=learn-cf-demo \
               ParameterKey=EnableVersioning,ParameterValue=true

# Kiểm tra Output trả về
aws cloudformation describe-stacks --stack-name my-first-s3-stack --query "Stacks[0].Outputs"
```
