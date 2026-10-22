// 05 - Reverse Array | Đảo ngược mảng
// Đề: Trả về mảng có thứ tự đảo ngược.
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Two pointers đổi chỗ phần tử đầu và cuối, tiến dần vào giữa.
// Độ phức tạp: Time O(n) / Space O(1) (đảo tại chỗ).
// Thực tế: Xử lý thứ tự dữ liệu (lịch sử, undo).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> reverseArray(vector<int> a){
    int l = 0, r = (int)a.size() - 1;
    while (l < r){
        swap(a[l], a[r]);
        l++;
        r--;
    }
    return a;
}

int main(){
    // Test case
    assert((reverseArray({1, 2, 3}) == vector<int>{3, 2, 1}));
    assert((reverseArray({}) == vector<int>{}));
    assert((reverseArray({5}) == vector<int>{5}));

    cout << "OK\n";
}
