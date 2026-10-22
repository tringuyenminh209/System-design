# 17 - Count Vowels | Đếm nguyên âm
# Ngôn ngữ: Python
# Đề: Đếm số nguyên âm a, e, i, o, u trong chuỗi.
# Ràng buộc: Không phân biệt hoa thường.
# Ý tưởng: Hạ về chữ thường rồi đếm ký tự thuộc tập nguyên âm.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Xử lý văn bản, thống kê ký tự.


def count_vowels(s):
    vowels = "aeiou"
    count = 0
    for ch in s.lower():  # lower(): hạ cả chuỗi về chữ thường -> "A" và "a" tính như nhau
        if ch in vowels:  # in: kiểm tra ký tự có nằm trong chuỗi "aeiou"
            count += 1
    return count


if __name__ == "__main__":
    # Test case
    assert count_vowels("hello") == 2
    assert count_vowels("XYZ") == 0
    assert count_vowels("AeIoU") == 5

    print("OK")
