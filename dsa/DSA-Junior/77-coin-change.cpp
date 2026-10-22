// 77 - Coin Change | Số đồng xu ít nhất đổi ra amount
// Đề: Số xu tối thiểu tạo ra amount, -1 nếu không thể.
// Ràng buộc: Mỗi loại xu dùng không giới hạn số lần.
// Ý tưởng: DP dưới lên - dp[a] = min xu để tạo a.
// Độ phức tạp: Time O(amount * loại_xu) / Space O(amount).
// Thực tế: DP tối ưu, bài toán đổi tiền kinh điển.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int coinChange(const vector<int>& coins, int amount){
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++){
        for (int c : coins){
            if (c <= a && dp[a - c] != INT_MAX)
                dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(){
    // Test case
    assert(coinChange({1, 2, 5}, 11) == 3);
    assert(coinChange({2}, 3) == -1);
    assert(coinChange({1}, 0) == 0);

    cout << "OK\n";
}
