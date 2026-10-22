// 87 - Partition Equal Subset Sum | Chia mảng thành 2 phần tổng bằng nhau
// Đề: Có thể chia mảng thành hai tập có tổng bằng nhau không.
// Ràng buộc: Tổng phải chẵn thì mới có khả năng.
// Ý tưởng: Quy về subset-sum bằng tổng/2, DP boolean theo trọng lượng.
// Độ phức tạp: Time O(n * sum) / Space O(sum).
// Thực tế: Bài toán tập con, biến thể của knapsack.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool canPartition(const vector<int>& a){
    int sum = 0;
    for (int x : a)
        sum += x;
    if (sum % 2)
        return false;
    int target = sum / 2;
    vector<char> dp(target + 1, 0);
    dp[0] = 1;
    for (int x : a){
        for (int c = target; c >= x; c--){
            if (dp[c - x])
                dp[c] = 1;
        }
    }
    return dp[target];
}

int main(){
    // Test case
    assert(canPartition({1, 5, 11, 5}));
    assert(!canPartition({1, 2, 3, 5}));

    cout << "OK\n";
}
