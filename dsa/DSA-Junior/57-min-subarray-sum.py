# 57 - Minimum Size Subarray Sum | Đoạn con ngắn nhất có tổng >= target
# Đề: Tìm độ dài nhỏ nhất của đoạn con liên tiếp có tổng >= target, 0 nếu không có.
# Ràng buộc: Các phần tử dương.
# Ý tưởng: Sliding window co giãn - mở rộng phải, thu hẹp trái khi đủ tổng.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Cửa sổ trượt theo điều kiện tổng.


def min_subarray_len(target, a):
    l = 0
    s = 0
    best = float("inf")
    for r, x in enumerate(a):
        s += x
        while s >= target:
            best = min(best, r - l + 1)
            s -= a[l]
            l += 1
    return 0 if best == float("inf") else best


if __name__ == "__main__":
    # Test case
    assert min_subarray_len(7, [2, 3, 1, 2, 4, 3]) == 2
    assert min_subarray_len(100, [1, 2, 3]) == 0

    print("OK")
