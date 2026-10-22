# 85 - Unique Paths | Số đường đi trong lưới (chỉ phải/xuống)
# Đề: Từ góc trên-trái tới dưới-phải lưới m*n, mỗi bước phải hoặc xuống; đếm số đường.
# Ràng buộc: 1 <= m, n <= 100.
# Ý tưởng: DP một hàng - dp[j] += dp[j-1] tích lũy theo từng hàng.
# Độ phức tạp: Time O(m*n) / Space O(n).
# Thực tế: Đếm tổ hợp đường đi; DP lưới cơ bản.


def unique_paths(m, n):
    dp = [1] * n
    for _ in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j - 1]
    return dp[n - 1]


if __name__ == "__main__":
    # Test case
    assert unique_paths(3, 7) == 28
    assert unique_paths(3, 2) == 3
    assert unique_paths(1, 1) == 1

    print("OK")
