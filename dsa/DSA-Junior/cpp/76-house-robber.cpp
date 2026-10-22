// 76 - House Robber | Trộm nhà không kề nhau, tối đa tiền
// Đề: Chọn tập nhà không liền kề sao cho tổng tiền lớn nhất.
// Ràng buộc: Mảng có thể rỗng (kết quả 0).
// Ý tưởng: DP - tại mỗi nhà chọn max(bỏ qua, lấy nhà này + trước-của-trước).
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: DP chọn/không-chọn với ràng buộc kề nhau.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int rob(const vector<int>& a){
    int prev = 0, cur = 0;
    for (int x : a){
        int take = max(cur, prev + x);
        prev = cur;
        cur = take;
    }
    return cur;
}

int main(){
    // Test case
    assert(rob({1, 2, 3, 1}) == 4);
    assert(rob({2, 7, 9, 3, 1}) == 12);
    assert(rob({}) == 0);

    cout << "OK\n";
}
