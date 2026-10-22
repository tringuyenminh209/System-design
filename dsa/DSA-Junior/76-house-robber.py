# 76 - House Robber | Trộm nhà không kề nhau, tối đa tiền
# Đề: Chọn tập nhà không liền kề sao cho tổng tiền lớn nhất.
# Ràng buộc: Mảng có thể rỗng (kết quả 0).
# Ý tưởng: DP - tại mỗi nhà chọn max(bỏ qua, lấy nhà này + trước-của-trước).
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: DP chọn/không-chọn với ràng buộc kề nhau.


def rob(a):
    prev = cur = 0
    for x in a:
        prev, cur = cur, max(cur, prev + x)
    return cur


if __name__ == "__main__":
    # Test case
    assert rob([1, 2, 3, 1]) == 4
    assert rob([2, 7, 9, 3, 1]) == 12
    assert rob([]) == 0

    print("OK")
