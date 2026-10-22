// 33 - Majority Element | Phần tử đa số (> n/2 lần)
// Đề: Tìm phần tử xuất hiện nhiều hơn n/2 lần.
// Ràng buộc: Đề bảo đảm phần tử đa số luôn tồn tại.
// Ý tưởng: Boyer-Moore voting - giữ ứng viên và bộ đếm.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Mẹo đếm bỏ phiếu kinh điển, tiết kiệm bộ nhớ.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int majority(const vector<int>& a){
    int candidate = 0, count = 0;
    for (int x : a){
        if (count == 0)
            candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    return candidate;
}

int main(){
    // Test case
    assert(majority({3, 2, 3}) == 3);
    assert(majority({2, 2, 1, 1, 1, 2, 2}) == 2);

    cout << "OK\n";
}
