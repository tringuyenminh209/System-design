// 07 - Fibonacci thứ n | Số Fibonacci thứ n
// Đề: F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2). Tính F(n).
// Ràng buộc: 0 <= n <= 90 (dùng long long).
// Ý tưởng: Lặp giữ 2 biến gần nhất, tránh đệ quy O(2^n).
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Ví dụ kinh điển dùng lặp thay đệ quy để tối ưu.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long fib(int n){
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++){
        long long c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    // Test case
    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(10) == 55);

    cout << "OK\n";
}
