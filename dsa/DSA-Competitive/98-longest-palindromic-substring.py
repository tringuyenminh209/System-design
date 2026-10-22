# 98 - Longest Palindromic Substring | Chuỗi con đối xứng dài nhất
# Đề: Trả về một chuỗi con đối xứng dài nhất.
# Ràng buộc: 1 <= |s| <= 1000.
# Ý tưởng: Nở từ tâm - với 2n-1 tâm (đơn và đôi), mở rộng khi hai bên còn khớp.
# Độ phức tạp: Time O(n^2) / Space O(1).
# Thực tế: Xử lý chuỗi; kỹ thuật expand-around-center dễ hiểu, đủ nhanh.


def longest_palindrome(s):
    if not s:
        return ""
    start, length = 0, 1

    def expand(l, r):
        nonlocal start, length
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        if r - l - 1 > length:
            length = r - l - 1
            start = l + 1

    for i in range(len(s)):
        expand(i, i)       # tâm đơn
        expand(i, i + 1)   # tâm đôi
    return s[start:start + length]


if __name__ == "__main__":
    # Test case
    assert longest_palindrome("babad") in ("bab", "aba")
    assert longest_palindrome("cbbd") == "bb"
    assert longest_palindrome("a") == "a"

    print("OK")
