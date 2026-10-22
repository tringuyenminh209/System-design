// 55 - Recursive Sum | Tổng 1..n bằng đệ quy
// Đề: Tính sum(n) = n + sum(n-1), với sum(0) = 0.
// Ràng buộc: n >= 0 (đủ nhỏ để không tràn ngăn xếp).
// Ý tưởng: Minh họa đệ quy có điều kiện dừng (base case).
// Độ phức tạp: Time O(n) / Space O(n) (ngăn xếp đệ quy).
// Thực tế: Hiểu base case, tránh đệ quy vô hạn.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long recursiveSum(int n){
    if (n <= 0)
        return 0;
    return n + recursiveSum(n - 1);
}

int main(){
    // Test case
    assert(recursiveSum(5) == 15);
    assert(recursiveSum(0) == 0);
    assert(recursiveSum(100) == 5050);

    cout << "OK\n";
}
