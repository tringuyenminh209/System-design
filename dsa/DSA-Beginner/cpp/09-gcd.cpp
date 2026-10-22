// 09 - GCD | Ước chung lớn nhất (thuật toán Euclid)
// Đề: Tìm ước chung lớn nhất của a và b.
// Ràng buộc: 0 <= a, b <= 1e18.
// Ý tưởng: gcd(a, b) = gcd(b, a % b), lặp tới khi b = 0.
// Độ phức tạp: Time O(log(min(a,b))) / Space O(1).
// Thực tế: Rút gọn phân số, đồng bộ chu kỳ.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long myGcd(long long a, long long b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    // Test case
    assert(myGcd(12, 18) == 6);
    assert(myGcd(5, 0) == 5);
    assert(myGcd(7, 13) == 1);

    cout << "OK\n";
}
