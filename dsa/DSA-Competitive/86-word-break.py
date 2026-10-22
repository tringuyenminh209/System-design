# 86 - Word Break | Tách chuỗi thành các từ trong từ điển
# Đề: s có thể tách thành dãy từ (được lặp) thuộc từ điển không.
# Ràng buộc: 1 <= |s| <= 300.
# Ý tưởng: DP - dp[i] = True nếu s[0..i) tách được; thử mọi điểm cắt j < i.
# Độ phức tạp: Time O(n^2 * L) / Space O(n).
# Thực tế: Tách token, kiểm tra hợp lệ chuỗi.


def word_break(s, words):
    d = set(words)
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in d:
                dp[i] = True
                break
    return dp[n]


if __name__ == "__main__":
    # Test case
    assert word_break("leetcode", ["leet", "code"])
    assert word_break("applepenapple", ["apple", "pen"])
    assert not word_break("catsandog", ["cats", "dog", "sand", "and", "cat"])

    print("OK")
