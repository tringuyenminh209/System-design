// 06 - Factorial | Giai thừa n!
// Đề: Tính n! = 1 * 2 * ... * n.
// Ràng buộc: 0 <= n <= 20 (dùng long long để tránh tràn số).
// Ý tưởng: Nhân dồn từ 2 tới n.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Nền tảng tổ hợp/xác suất; chú ý tràn số với n lớn.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long factorial(int n){
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main(){
    // Test case
    assert(factorial(0) == 1);
    assert(factorial(5) == 120);
    assert(factorial(10) == 3628800);

    cout << "OK\n";
}
