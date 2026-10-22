# 51 - Running Sum | Tổng tiền tố (prefix sum)
# Đề: Trả về mảng r với r[i] = a[0] + a[1] + ... + a[i].
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Cộng dồn tại chỗ a[i] += a[i-1].
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Nền tảng tính tổng đoạn nhanh (range sum) trong O(1).


def running_sum(a):
    a = a[:]
    for i in range(1, len(a)):
        a[i] += a[i - 1]
    return a


if __name__ == "__main__":
    # Test case
    assert running_sum([1, 2, 3, 4]) == [1, 3, 6, 10]
    assert running_sum([3, 1, 2, 10, 1]) == [3, 4, 6, 16, 17]

    print("OK")
