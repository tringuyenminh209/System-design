# 84 - 0/1 Knapsack | Cái túi 0/1
# Đề: Chọn tập đồ (mỗi món 0 hoặc 1) sao cho tổng nặng <= W và tổng giá trị lớn nhất.
# Ràng buộc: 1 <= n, W <= vài nghìn.
# Ý tưởng: DP 1 chiều, duyệt trọng lượng GIẢM dần để mỗi món dùng tối đa một lần.
# Độ phức tạp: Time O(n*W) / Space O(W).
# Thực tế: Bài DP tối ưu tài nguyên (ngân sách, dung lượng).


def knapsack(w, v, W):
    dp = [0] * (W + 1)
    for i in range(len(w)):
        for c in range(W, w[i] - 1, -1):
            dp[c] = max(dp[c], dp[c - w[i]] + v[i])
    return dp[W]


if __name__ == "__main__":
    # Test case
    assert knapsack([1, 3, 4, 5], [1, 4, 5, 7], 7) == 9
    assert knapsack([2], [3], 1) == 0

    print("OK")
