// 10 - LCM | Bội chung nhỏ nhất
// Đề: Tìm bội chung nhỏ nhất của a và b.
// Ràng buộc: 1 <= a, b <= 1e9 (kết quả vừa long long).
// Ý tưởng: lcm = a / gcd(a, b) * b (chia trước để tránh tràn số).
// Độ phức tạp: Time O(log(min(a,b))) / Space O(1).
// Thực tế: Đồng bộ hai chu kỳ khác nhau.

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: ước chung lớn nhất
long long myGcd(long long a, long long b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

// Hàm giải quyết bài toán
long long lcm(long long a, long long b){
    return a / myGcd(a, b) * b;
}

int main(){
    // Test case
    assert(lcm(4, 6) == 12);
    assert(lcm(3, 5) == 15);
    assert(lcm(6, 6) == 6);

    cout << "OK\n";
}
