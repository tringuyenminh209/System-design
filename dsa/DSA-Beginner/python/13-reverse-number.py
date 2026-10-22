# 13 - Reverse Number | Đảo ngược số (không âm)
# Đề: Đảo ngược các chữ số của n, ví dụ 123 -> 321, 120 -> 21.
# Ràng buộc: n >= 0.
# Ý tưởng: Bóc chữ số cuối (n % 10) và dựng lại số theo chiều ngược.
# Độ phức tạp: Time O(log n) / Space O(1).
# Thực tế: Xử lý số kiểu chuỗi mà không cần chuyển sang string.


def reverse_number(n):
    result = 0
    while n:
        result = result * 10 + n % 10
        n //= 10
    return result


if __name__ == "__main__":
    # Test case
    assert reverse_number(123) == 321
    assert reverse_number(120) == 21
    assert reverse_number(0) == 0

    print("OK")
