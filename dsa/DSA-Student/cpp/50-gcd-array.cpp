// 50 - GCD of Array | Ước chung lớn nhất của cả mảng
// Đề: Tìm ước chung lớn nhất của mọi phần tử trong mảng.
// Ràng buộc: Mảng không rỗng, các phần tử >= 0.
// Ý tưởng: gcd tích lũy - g = gcd(g, a[i]) qua từng phần tử.
// Độ phức tạp: Time O(n log(max)) / Space O(1).
// Thực tế: Rút gọn dãy tỉ lệ, tìm bước chung.

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: ước chung lớn nhất hai số
long long gcd(long long a, long long b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

// Hàm giải quyết bài toán
long long gcdArray(const vector<int>& a){
    long long g = 0;
    for (int x : a)
        g = gcd(g, x);
    return g;
}

int main(){
    // Test case
    assert(gcdArray({12, 18, 24}) == 6);
    assert(gcdArray({7}) == 7);
    assert(gcdArray({5, 10, 15}) == 5);

    cout << "OK\n";
}
