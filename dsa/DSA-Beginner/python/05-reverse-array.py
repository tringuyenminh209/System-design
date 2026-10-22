# 05 - Reverse Array | Đảo ngược mảng
# Đề: Trả về mảng có thứ tự đảo ngược.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Dùng slicing a[::-1].
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Xử lý thứ tự dữ liệu (lịch sử, undo).


def reverse_array(a):
    return a[::-1]


if __name__ == "__main__":
    # Test case
    assert reverse_array([1, 2, 3]) == [3, 2, 1]
    assert reverse_array([]) == []
    assert reverse_array([5]) == [5]

    print("OK")
