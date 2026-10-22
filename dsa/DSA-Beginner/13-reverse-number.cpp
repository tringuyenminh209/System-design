// 13 - Reverse Number | Đảo ngược số (không âm)
// Đề: Đảo ngược các chữ số của n, ví dụ 123 -> 321, 120 -> 21.
// Ràng buộc: 0 <= n <= 1e18.
// Ý tưởng: Bóc chữ số cuối (n % 10) và dựng lại số theo chiều ngược.
// Độ phức tạp: Time O(log n) / Space O(1).
// Thực tế: Xử lý số kiểu chuỗi mà không cần chuyển sang string.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long reverseNumber(long long n){
    long long result = 0;
    while (n){
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

int main(){
    // Test case
    assert(reverseNumber(123) == 321);
    assert(reverseNumber(120) == 21);
    assert(reverseNumber(0) == 0);

    cout << "OK\n";
}
