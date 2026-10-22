// 82 - Edit Distance | Khoảng cách chỉnh sửa (Levenshtein)
// Đề: Số phép chèn/xóa/thay ít nhất để biến chuỗi a thành b.
// Ràng buộc: 0 <= |a|, |b| <= 1000.
// Ý tưởng: DP bảng dp[i][j] = chi phí biến a[0..i) thành b[0..j).
// Độ phức tạp: Time O(n*m) / Space O(n*m).
// Thực tế: Gợi ý sửa lỗi chính tả, so khớp mờ (fuzzy match).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int minDistance(const string& a, const string& b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    return dp[n][m];
}

int main(){
    // Test case
    assert(minDistance("horse", "ros") == 3);
    assert(minDistance("intention", "execution") == 5);
    assert(minDistance("", "abc") == 3);

    cout << "OK\n";
}
