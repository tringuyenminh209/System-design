# 49 - Two Sum II (mảng đã sắp) | Tìm cặp có tổng target
# Đề: Mảng tăng dần, trả về chỉ số (0-based) của cặp có tổng bằng target.
# Ràng buộc: Mảng đã sắp; giả định luôn có đáp án.
# Ý tưởng: Two pointers - tổng nhỏ thì tiến trái, lớn thì lùi phải.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Khai thác thứ tự để tiết kiệm bộ nhớ so với HashMap.


def two_sum_sorted(a, target):
    l, r = 0, len(a) - 1
    while l < r:
        s = a[l] + a[r]
        if s == target:
            return (l, r)
        if s < target:
            l += 1
        else:
            r -= 1
    return (-1, -1)


if __name__ == "__main__":
    # Test case
    assert two_sum_sorted([2, 7, 11, 15], 9) == (0, 1)
    assert two_sum_sorted([2, 3, 4], 6) == (0, 2)

    print("OK")
