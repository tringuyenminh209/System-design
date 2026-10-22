// 44 - Best Time to Buy/Sell Stock | Lợi nhuận tối đa một lần mua-bán
// Đề: Mua một ngày, bán một ngày sau đó; tối đa lợi nhuận (0 nếu không có lãi).
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Giữ giá thấp nhất đã thấy, thử bán tại mỗi ngày.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Mẫu "min so far", tối ưu một biến trạng thái.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int maxProfit(const vector<int>& prices){
    int lo = INT_MAX, best = 0;
    for (int x : prices){
        lo = min(lo, x);
        best = max(best, x - lo);
    }
    return best;
}

int main(){
    // Test case
    assert(maxProfit({7, 1, 5, 3, 6, 4}) == 5);
    assert(maxProfit({7, 6, 4, 3, 1}) == 0);

    cout << "OK\n";
}
