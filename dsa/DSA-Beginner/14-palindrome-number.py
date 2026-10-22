# 14 - Palindrome Number | Số đối xứng
# Đề: Kiểm tra n có đọc xuôi ngược giống nhau không.
# Ràng buộc: Số âm luôn không đối xứng (trả về False).
# Ý tưởng: Đảo ngược số rồi so sánh với số gốc.
# Độ phức tạp: Time O(log n) / Space O(1).
# Thực tế: Kiểm tra tính đối xứng của dữ liệu.


def is_palindrome(n):
    if n < 0:
        return False
    t, reversed_n = n, 0
    while t:
        reversed_n = reversed_n * 10 + t % 10
        t //= 10
    return reversed_n == n


if __name__ == "__main__":
    # Test case
    assert is_palindrome(121)
    assert not is_palindrome(123)
    assert not is_palindrome(-121)
    assert is_palindrome(0)

    print("OK")
