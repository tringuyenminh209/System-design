// 99 - Maximum Product Subarray | Tích đoạn con lớn nhất
// Đề: Tìm tích lớn nhất của một đoạn con liên tiếp.
// Ràng buộc: Mảng không rỗng; có thể chứa số âm và số 0.
// Ý tưởng: Giữ CẢ max và min hiện tại (số âm đảo dấu min thành max).
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Biến thể Kadane có bẫy số âm và số 0.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int maxProduct(const vector<int>& a){
    int best = a[0], mx = a[0], mn = a[0];
    for (int i = 1; i < (int)a.size(); i++){
        int x = a[i];
        if (x < 0)
            swap(mx, mn);
        mx = max(x, mx * x);
        mn = min(x, mn * x);
        best = max(best, mx);
    }
    return best;
}

int main(){
    // Test case
    assert(maxProduct({2, 3, -2, 4}) == 6);
    assert(maxProduct({-2, 0, -1}) == 0);
    assert(maxProduct({-2, 3, -4}) == 24);

    cout << "OK\n";
}
