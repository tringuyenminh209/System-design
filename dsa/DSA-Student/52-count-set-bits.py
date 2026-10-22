# 52 - Count Set Bits | Đếm số bit 1
# Đề: Đếm số bit 1 trong biểu diễn nhị phân của n >= 0.
# Ràng buộc: n >= 0.
# Ý tưởng: Mẹo Brian Kernighan - n &= (n-1) xóa bit 1 thấp nhất mỗi lần.
# Độ phức tạp: Time O(số bit 1) / Space O(1).
# Thực tế: Xử lý cờ (flags), đếm phần tử tập con dạng bitmask.


def count_set_bits(n):
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count


if __name__ == "__main__":
    # Test case
    assert count_set_bits(11) == 3
    assert count_set_bits(128) == 1
    assert count_set_bits(0) == 0

    print("OK")
