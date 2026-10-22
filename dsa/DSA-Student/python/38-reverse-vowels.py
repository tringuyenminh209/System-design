# 38 - Reverse Vowels | Đảo vị trí các nguyên âm
# Đề: Chỉ đảo chỗ các nguyên âm, giữ nguyên phụ âm. Ví dụ hello -> holle.
# Ràng buộc: Nguyên âm không phân biệt hoa thường.
# Ý tưởng: Two pointers, chỉ đổi chỗ khi cả hai đầu đều là nguyên âm.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Two pointers có điều kiện lọc.


def reverse_vowels(s):
    vowels = set("aeiouAEIOU")
    a = list(s)
    l, r = 0, len(a) - 1
    while l < r:
        if a[l] not in vowels:
            l += 1
        elif a[r] not in vowels:
            r -= 1
        else:
            a[l], a[r] = a[r], a[l]
            l += 1
            r -= 1
    return "".join(a)


if __name__ == "__main__":
    # Test case
    assert reverse_vowels("hello") == "holle"
    assert reverse_vowels("leetcode") == "leotcede"

    print("OK")
