// 41 - Single Number | Số xuất hiện một lần
// Đề: Mọi phần tử xuất hiện 2 lần trừ đúng 1 phần tử; tìm phần tử đó.
// Ràng buộc: Đúng một phần tử lẻ, còn lại theo cặp.
// Ý tưởng: XOR toàn mảng - các cặp giống nhau triệt tiêu về 0.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Mẹo XOR kinh điển, tiết kiệm bộ nhớ.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int singleNumber(const vector<int>& a){
    int x = 0;
    for (int v : a)
        x ^= v;
    return x;
}

int main(){
    // Test case
    assert(singleNumber({2, 2, 1}) == 1);
    assert(singleNumber({4, 1, 2, 1, 2}) == 4);

    cout << "OK\n";
}
