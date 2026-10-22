// 43 - Maximum Subarray | Tổng đoạn con lớn nhất (Kadane)
// Đề: Tìm tổng lớn nhất của một đoạn con liên tiếp không rỗng.
// Ràng buộc: Mảng không rỗng; có thể chứa số âm.
// Ý tưởng: Kadane - cur = max(x, cur + x); best = max(best, cur).
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Chuỗi lãi/lỗ tốt nhất, đoạn tín hiệu mạnh nhất.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int maxSubArray(const vector<int>& a){
    int best = a[0], cur = a[0];
    for (int i = 1; i < (int)a.size(); i++){
        cur = max(a[i], cur + a[i]);
        best = max(best, cur);
    }
    return best;
}

int main(){
    // Test case
    assert(maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    assert(maxSubArray({-1, -2, -3}) == -1);

    cout << "OK\n";
}
