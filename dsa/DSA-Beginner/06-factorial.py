# 06 - Factorial | Giai thừa n!
# Đề: Tính n! = 1 * 2 * ... * n.
# Ràng buộc: n >= 0 (Python tự xử lý số lớn, không lo tràn).
# Ý tưởng: Nhân dồn từ 2 tới n.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Nền tảng tổ hợp/xác suất.


def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


if __name__ == "__main__":
    # Test case
    assert factorial(0) == 1
    assert factorial(5) == 120
    assert factorial(10) == 3628800

    print("OK")
