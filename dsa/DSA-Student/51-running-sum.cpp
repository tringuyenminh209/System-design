// 51 - Running Sum | Tổng tiền tố (prefix sum)
// Đề: Trả về mảng r với r[i] = a[0] + a[1] + ... + a[i].
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Cộng dồn tại chỗ a[i] += a[i-1].
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Nền tảng tính tổng đoạn nhanh (range sum) trong O(1).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> runningSum(vector<int> a){
    for (int i = 1; i < (int)a.size(); i++)
        a[i] += a[i - 1];
    return a;
}

int main(){
    // Test case
    assert((runningSum({1, 2, 3, 4}) == vector<int>{1, 3, 6, 10}));
    assert((runningSum({3, 1, 2, 10, 1}) == vector<int>{3, 4, 6, 16, 17}));

    cout << "OK\n";
}
