# 31 - First Unique Char | Ký tự đầu tiên không lặp
# Đề: Trả về chỉ số ký tự xuất hiện đúng một lần đầu tiên, -1 nếu không có.
# Ràng buộc: Chuỗi bất kỳ.
# Ý tưởng: Đếm tần suất mọi ký tự, rồi duyệt lại tìm ký tự có tần suất 1.
# Độ phức tạp: Time O(n) / Space O(1) (bảng chữ cái hữu hạn).
# Thực tế: Xử lý chuỗi, lọc phần tử duy nhất.

from collections import Counter


def first_uniq_char(s):
    cnt = Counter(s)
    for i, c in enumerate(s):
        if cnt[c] == 1:
            return i
    return -1


if __name__ == "__main__":
    # Test case
    assert first_uniq_char("leetcode") == 0
    assert first_uniq_char("loveleetcode") == 2
    assert first_uniq_char("aabb") == -1

    print("OK")
