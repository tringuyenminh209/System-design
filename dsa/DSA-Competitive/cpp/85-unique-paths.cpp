// 85 - Unique Paths | Số đường đi trong lưới (chỉ phải/xuống)
// Đề: Từ góc trên-trái tới dưới-phải lưới m*n, mỗi bước đi phải hoặc xuống; đếm số đường.
// Ràng buộc: 1 <= m, n <= 100.
// Ý tưởng: DP một hàng - dp[j] += dp[j-1] tích lũy theo từng hàng.
// Độ phức tạp: Time O(m*n) / Space O(n).
// Thực tế: Đếm tổ hợp đường đi; DP lưới cơ bản.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long uniquePaths(int m, int n){
    vector<long long> dp(n, 1);
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1];
    }
    return dp[n - 1];
}

int main(){
    // Test case
    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);
    assert(uniquePaths(1, 1) == 1);

    cout << "OK\n";
}
