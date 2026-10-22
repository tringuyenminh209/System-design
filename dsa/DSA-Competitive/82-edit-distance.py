# 82 - Edit Distance | Khoảng cách chỉnh sửa (Levenshtein)
# Đề: Số phép chèn/xóa/thay ít nhất để biến chuỗi a thành b.
# Ràng buộc: 0 <= |a|, |b| <= 1000.
# Ý tưởng: DP bảng dp[i][j] = chi phí biến a[0..i) thành b[0..j).
# Độ phức tạp: Time O(n*m) / Space O(n*m).
# Thực tế: Gợi ý sửa lỗi chính tả, so khớp mờ (fuzzy match).


def min_distance(a, b):
    n, m = len(a), len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = i
    for j in range(m + 1):
        dp[0][j] = j
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[n][m]


if __name__ == "__main__":
    # Test case
    assert min_distance("horse", "ros") == 3
    assert min_distance("intention", "execution") == 5
    assert min_distance("", "abc") == 3

    print("OK")
