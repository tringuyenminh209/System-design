// 84 - 0/1 Knapsack | Cái túi 0/1
// Đề: Chọn tập đồ (mỗi món lấy 0 hoặc 1) sao cho tổng nặng <= W và tổng giá trị lớn nhất.
// Ràng buộc: 1 <= n, W <= vài nghìn.
// Ý tưởng: DP 1 chiều, duyệt trọng lượng GIẢM dần để mỗi món dùng tối đa một lần.
// Độ phức tạp: Time O(n*W) / Space O(W).
// Thực tế: Bài DP tối ưu tài nguyên (ngân sách, dung lượng).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int knapsack(const vector<int>& w, const vector<int>& v, int W){
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); i++){
        for (int c = W; c >= w[i]; c--)
            dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    }
    return dp[W];
}

int main(){
    // Test case
    assert(knapsack({1, 3, 4, 5}, {1, 4, 5, 7}, 7) == 9);
    assert(knapsack({2}, {3}, 1) == 0);

    cout << "OK\n";
}
