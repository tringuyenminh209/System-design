# 77 - Coin Change | Số đồng xu ít nhất đổi ra amount
# Đề: Số xu tối thiểu tạo ra amount, -1 nếu không thể.
# Ràng buộc: Mỗi loại xu dùng không giới hạn số lần.
# Ý tưởng: DP dưới lên - dp[a] = min xu để tạo a.
# Độ phức tạp: Time O(amount * loại_xu) / Space O(amount).
# Thực tế: DP tối ưu, bài toán đổi tiền kinh điển.


def coin_change(coins, amount):
    INF = float("inf")
    dp = [0] + [INF] * amount
    for a in range(1, amount + 1):
        for c in coins:
            if c <= a and dp[a - c] + 1 < dp[a]:
                dp[a] = dp[a - c] + 1
    return -1 if dp[amount] == INF else dp[amount]


if __name__ == "__main__":
    # Test case
    assert coin_change([1, 2, 5], 11) == 3
    assert coin_change([2], 3) == -1
    assert coin_change([1], 0) == 0

    print("OK")
