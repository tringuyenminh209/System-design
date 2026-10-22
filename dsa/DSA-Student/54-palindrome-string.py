# 54 - Palindrome String | Chuỗi đối xứng
# Đề: Kiểm tra chuỗi đọc xuôi ngược có giống nhau không.
# Ràng buộc: So sánh chính xác từng ký tự.
# Ý tưởng: Two pointers so ký tự đầu và cuối, tiến dần vào giữa.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Kiểm tra đối xứng; biến thể: bỏ qua ký tự không phải chữ-số.


def is_palindrome(s):
    l, r = 0, len(s) - 1
    while l < r:
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True


if __name__ == "__main__":
    # Test case
    assert is_palindrome("racecar")
    assert not is_palindrome("hello")
    assert is_palindrome("")

    print("OK")
