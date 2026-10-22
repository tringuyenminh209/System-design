# 36 - Rotate Array | Xoay phải k bước
# Đề: Xoay phải mảng k bước, ví dụ [1,2,3,4,5] k=2 -> [4,5,1,2,3].
# Ràng buộc: k có thể lớn hơn n (cần k %= n).
# Ý tưởng: Dùng slicing sau khi k %= n.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Dịch vòng dữ liệu (con trỏ vòng, buffer tuần hoàn).


def rotate(a, k):
    n = len(a)
    if n == 0:
        return a[:]
    k %= n
    if k == 0:
        return a[:]
    return a[-k:] + a[:-k]


if __name__ == "__main__":
    # Test case
    assert rotate([1, 2, 3, 4, 5], 2) == [4, 5, 1, 2, 3]
    assert rotate([1, 2], 3) == [2, 1]

    print("OK")
