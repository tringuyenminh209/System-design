// 48 - Count Primes | Đếm số nguyên tố nhỏ hơn n
// Đề: Đếm số nguyên tố trong khoảng [2, n).
// Ràng buộc: 0 <= n <= 5e6.
// Ý tưởng: Sàng Eratosthenes - gạch bội của mỗi số nguyên tố.
// Độ phức tạp: Time O(n log log n) / Space O(n).
// Thực tế: Tiền xử lý nhanh cho nhiều truy vấn về nguyên tố.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int countPrimes(int n){
    if (n < 3)
        return 0;
    vector<char> composite(n, 0);
    int count = 0;
    for (int i = 2; i < n; i++){
        if (!composite[i]){
            count++;
            for (long long j = (long long)i * i; j < n; j += i)
                composite[j] = 1;
        }
    }
    return count;
}

int main(){
    // Test case
    assert(countPrimes(10) == 4);
    assert(countPrimes(2) == 0);
    assert(countPrimes(0) == 0);

    cout << "OK\n";
}
