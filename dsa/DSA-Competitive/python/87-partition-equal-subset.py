# 87 - Partition Equal Subset Sum | Chia mảng thành 2 phần tổng bằng nhau
# Đề: Có thể chia mảng thành hai tập có tổng bằng nhau không.
# Ràng buộc: Tổng phải chẵn thì mới có khả năng.
# Ý tưởng: Quy về subset-sum bằng tổng/2, DP boolean theo trọng lượng.
# Độ phức tạp: Time O(n * sum) / Space O(sum).
# Thực tế: Bài toán tập con, biến thể của knapsack.


def can_partition(a):
    total = sum(a)
    if total % 2:
        return False
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    for x in a:
        for c in range(target, x - 1, -1):
            if dp[c - x]:
                dp[c] = True
    return dp[target]


if __name__ == "__main__":
    # Test case
    assert can_partition([1, 5, 11, 5])
    assert not can_partition([1, 2, 3, 5])

    print("OK")
