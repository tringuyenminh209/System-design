// 83 - Longest Common Subsequence | Dãy con chung dài nhất
// Đề: Độ dài dãy con chung dài nhất của hai chuỗi.
// Ràng buộc: 0 <= |a|, |b| <= 1000.
// Ý tưởng: DP bảng hai chiều dựa trên khớp/không khớp ký tự cuối.
// Độ phức tạp: Time O(n*m) / Space O(n*m).
// Thực tế: Diff văn bản, so sánh phiên bản (ý tưởng gần với git diff).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int lcs(const string& a, const string& b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main(){
    // Test case
    assert(lcs("abcde", "ace") == 3);
    assert(lcs("abc", "abc") == 3);
    assert(lcs("abc", "def") == 0);

    cout << "OK\n";
}
