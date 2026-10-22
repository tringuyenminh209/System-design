// 12 - Count Digits | Đếm số chữ số
// Đề: Đếm số chữ số của |n| (quy ước 0 có 1 chữ số).
// Ràng buộc: -1e18 <= n <= 1e18.
// Ý tưởng: Chia cho 10 tới khi hết, mỗi lần tăng bộ đếm.
// Độ phức tạp: Time O(log n) / Space O(1).
// Thực tế: Định dạng hiển thị, căn lề số.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int countDigits(long long n){
    n = llabs(n);
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n);
    return count;
}

int main(){
    // Test case
    assert(countDigits(123) == 3);
    assert(countDigits(0) == 1);
    assert(countDigits(-4567) == 4);

    cout << "OK\n";
}
