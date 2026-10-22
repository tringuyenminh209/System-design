# 37 - Valid Anagram | Hai chuỗi có phải đảo chữ của nhau
# Đề: Kiểm tra s và t có cùng đa tập ký tự không.
# Ràng buộc: Chuỗi bất kỳ.
# Ý tưởng: So sánh hai Counter tần suất ký tự.
# Độ phức tạp: Time O(n) / Space O(1) (bảng chữ cái hữu hạn).
# Thực tế: Nhóm từ, kiểm tra hoán vị ký tự.

from collections import Counter


def is_anagram(s, t):
    return Counter(s) == Counter(t)


if __name__ == "__main__":
    # Test case
    assert is_anagram("anagram", "nagaram")
    assert not is_anagram("rat", "car")
    assert is_anagram("", "")

    print("OK")
