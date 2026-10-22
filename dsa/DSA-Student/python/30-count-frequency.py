# 30 - Count Frequency | Đếm tần suất mỗi giá trị
# Đề: Trả về dict giá_trị -> số_lần xuất hiện.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Dùng Counter (builtin) cộng dồn khi duyệt.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Thống kê, tìm phần tử phổ biến.

from collections import Counter


def count_freq(a):
    return dict(Counter(a))


if __name__ == "__main__":
    # Test case
    assert count_freq([1, 1, 2, 3, 3, 3]) == {1: 2, 2: 1, 3: 3}
    assert count_freq([]) == {}

    print("OK")
