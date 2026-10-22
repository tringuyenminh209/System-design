# 16 - Average | Trung bình cộng
# Đề: Trả về trung bình cộng (kiểu float) của mảng.
# Ràng buộc: Mảng không rỗng (n >= 1).
# Ý tưởng: Tổng các phần tử chia cho số lượng.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Thống kê cơ bản; Python chia / cho ra float sẵn.


def average(a):
    return sum(a) / len(a)


if __name__ == "__main__":
    # Test case
    assert average([1, 2, 3, 4]) == 2.5
    assert average([5]) == 5.0

    print("OK")
