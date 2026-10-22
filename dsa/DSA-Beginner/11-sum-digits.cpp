// 11 - Sum of Digits | Tổng các chữ số
// Đề: Tính tổng các chữ số của |n|.
// Ràng buộc: -1e18 <= n <= 1e18.
// Ý tưởng: Lấy chữ số cuối bằng n % 10, rồi bỏ đi bằng n /= 10.
// Độ phức tạp: Time O(số chữ số) / Space O(1).
// Thực tế: Checksum, kiểm tra chia hết cho 9.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int sumDigits(long long n){
    n = llabs(n);
    int sum = 0;
    do {
        sum += n % 10;
        n /= 10;
    } while (n);
    return sum;
}

int main(){
    // Test case
    assert(sumDigits(123) == 6);
    assert(sumDigits(0) == 0);
    assert(sumDigits(-99) == 18);

    cout << "OK\n";
}
