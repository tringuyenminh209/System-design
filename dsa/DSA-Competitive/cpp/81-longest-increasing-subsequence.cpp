// 81 - Longest Increasing Subsequence | Dãy con tăng dài nhất
// Đề: Tìm độ dài dãy con (không cần liên tiếp) tăng ngặt dài nhất.
// Ràng buộc: 1 <= n <= 1e5.
// Ý tưởng: Patience sorting - giữ mảng "đuôi nhỏ nhất", dùng lower_bound để thay/nối.
// Độ phức tạp: Time O(n log n) / Space O(n).
// Thực tế: Mẫu LIS kinh điển (phân tích xu hướng, xếp chồng hộp).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int lengthOfLIS(const vector<int>& a){
    vector<int> tails;
    for (int x : a){
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    return tails.size();
}

int main(){
    // Test case
    assert(lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lengthOfLIS({0, 1, 0, 3, 2, 3}) == 4);
    assert(lengthOfLIS({7, 7, 7}) == 1);

    cout << "OK\n";
}
