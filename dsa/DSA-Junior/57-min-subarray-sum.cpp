// 57 - Minimum Size Subarray Sum | Đoạn con ngắn nhất có tổng >= target
// Đề: Tìm độ dài nhỏ nhất của đoạn con liên tiếp có tổng >= target, 0 nếu không có.
// Ràng buộc: Các phần tử dương.
// Ý tưởng: Sliding window co giãn - mở rộng phải, thu hẹp trái khi đủ tổng.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Cửa sổ trượt theo điều kiện tổng.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int minSubArrayLen(int target, const vector<int>& a){
    int l = 0, sum = 0, best = INT_MAX;
    for (int r = 0; r < (int)a.size(); r++){
        sum += a[r];
        while (sum >= target){
            best = min(best, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main(){
    // Test case
    assert(minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) == 2);
    assert(minSubArrayLen(100, {1, 2, 3}) == 0);

    cout << "OK\n";
}
