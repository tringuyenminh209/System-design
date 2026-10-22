# 53 - Reverse Words | Đảo thứ tự các từ
# Đề: "the sky is blue" -> "blue is sky the".
# Ràng buộc: Các từ cách nhau bởi dấu cách.
# Ý tưởng: Tách chuỗi thành các từ rồi ghép lại theo thứ tự ngược.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Xử lý câu, chuẩn hóa chuỗi.


def reverse_words(s):
    return " ".join(s.split()[::-1])


if __name__ == "__main__":
    # Test case
    assert reverse_words("the sky is blue") == "blue is sky the"
    assert reverse_words("hello") == "hello"

    print("OK")
