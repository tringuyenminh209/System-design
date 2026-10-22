// 52 - Count Set Bits | Đếm số bit 1
// Đề: Đếm số bit 1 trong biểu diễn nhị phân của n >= 0.
// Ràng buộc: 0 <= n <= 1e18.
// Ý tưởng: Mẹo Brian Kernighan - n &= (n-1) xóa bit 1 thấp nhất mỗi lần.
// Độ phức tạp: Time O(số bit 1) / Space O(1).
// Thực tế: Xử lý cờ (flags), đếm phần tử tập con dạng bitmask.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int countSetBits(long long n){
    int count = 0;
    while (n){
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(){
    // Test case
    assert(countSetBits(11) == 3);
    assert(countSetBits(128) == 1);
    assert(countSetBits(0) == 0);

    cout << "OK\n";
}
