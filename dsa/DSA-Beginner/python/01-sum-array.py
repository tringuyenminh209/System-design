# 01 - Sum Array | Tổng các phần tử mảng
# Đề: Cho mảng số nguyên, trả về tổng các phần tử.
# Ràng buộc: 1 <= n <= 1e5; mảng có thể rỗng (tổng = 0).
# Ý tưởng: Cộng dồn một lần duyệt (dùng builtin sum).
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Nền tảng của mọi phép tổng hợp dữ liệu.


def sum_array(a):
    return sum(a)


if __name__ == "__main__":
    # Test case
    assert sum_array([1, 2, 3, 4]) == 10
    assert sum_array([]) == 0
    assert sum_array([-1, 1]) == 0

    print("OK")
