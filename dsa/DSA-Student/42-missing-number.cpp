// 42 - Missing Number | Số thiếu trong 0..n
// Đề: Mảng chứa n số phân biệt trong [0..n]; tìm số bị thiếu.
// Ràng buộc: Đúng một số trong [0..n] bị thiếu.
// Ý tưởng: Tổng kỳ vọng 0+1+..+n trừ đi tổng thực tế.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Kiểm tra dãy liên tục có bị hụt phần tử.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int missingNumber(const vector<int>& a){
    long long n = a.size();
    long long sum = n * (n + 1) / 2;
    for (int x : a)
        sum -= x;
    return (int)sum;
}

int main(){
    // Test case
    assert(missingNumber({3, 0, 1}) == 2);
    assert(missingNumber({0, 1}) == 2);
    assert(missingNumber({0}) == 1);

    cout << "OK\n";
}
