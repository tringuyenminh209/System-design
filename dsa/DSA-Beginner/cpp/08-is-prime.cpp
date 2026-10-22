// 08 - Is Prime | Kiểm tra số nguyên tố
// Đề: Kiểm tra n có phải số nguyên tố không.
// Ràng buộc: n có thể tới 1e18 (dùng long long).
// Ý tưởng: Thử các ước từ 2 tới sqrt(n); có ước thì không nguyên tố.
// Độ phức tạp: Time O(sqrt(n)) / Space O(1).
// Thực tế: Cơ sở nhiều bài số học; mẹo dừng ở căn bậc hai.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool isPrime(long long n){
    if (n < 2)
        return false;
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    // Test case
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(17));
    assert(!isPrime(18));

    cout << "OK\n";
}
