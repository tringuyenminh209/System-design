# 83 - Longest Common Subsequence | Dãy con chung dài nhất
# Đề: Độ dài dãy con chung dài nhất của hai chuỗi.
# Ràng buộc: 0 <= |a|, |b| <= 1000.
# Ý tưởng: DP bảng hai chiều dựa trên khớp/không khớp ký tự cuối.
# Độ phức tạp: Time O(n*m) / Space O(n*m).
# Thực tế: Diff văn bản, so sánh phiên bản (ý tưởng gần với git diff).


def lcs(a, b):
    n, m = len(a), len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[n][m]


if __name__ == "__main__":
    # Test case
    assert lcs("abcde", "ace") == 3
    assert lcs("abc", "abc") == 3
    assert lcs("abc", "def") == 0

    print("OK")
