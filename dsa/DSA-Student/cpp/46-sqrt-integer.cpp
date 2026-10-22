// 46 - Integer Sqrt | Căn bậc hai làm tròn xuống
// Đề: Tính floor(sqrt(x)) cho x >= 0, chỉ dùng số nguyên.
// Ràng buộc: 0 <= x <= 1e18.
// Ý tưởng: Nhị phân trên đáp án - tìm m lớn nhất mà m*m <= x.
// Độ phức tạp: Time O(log x) / Space O(1).
// Thực tế: Binary search trên không gian giá trị (không chỉ trên mảng).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int mySqrt(long long x){
    long long lo = 0, hi = x, ans = 0;
    while (lo <= hi){
        long long m = lo + (hi - lo) / 2;
        if (m * m <= x){
            ans = m;
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return (int)ans;
}

int main(){
    // Test case
    assert(mySqrt(8) == 2);
    assert(mySqrt(16) == 4);
    assert(mySqrt(0) == 0);
    assert(mySqrt(1) == 1);

    cout << "OK\n";
}
