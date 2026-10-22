// 47 - Power of Two | Kiểm tra lũy thừa của 2
// Đề: Kiểm tra n có phải 2^k (k >= 0) không.
// Ràng buộc: n là số nguyên bất kỳ.
// Ý tưởng: Số dương chỉ có đúng 1 bit bật khi n & (n-1) == 0.
// Độ phức tạp: Time O(1) / Space O(1).
// Thực tế: Mẹo bit-manipulation hay dùng (căn chỉnh bộ nhớ, hash size).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool isPowerOfTwo(long long n){
    return n > 0 && (n & (n - 1)) == 0;
}

int main(){
    // Test case
    assert(isPowerOfTwo(1));
    assert(isPowerOfTwo(16));
    assert(!isPowerOfTwo(3));
    assert(!isPowerOfTwo(0));

    cout << "OK\n";
}
