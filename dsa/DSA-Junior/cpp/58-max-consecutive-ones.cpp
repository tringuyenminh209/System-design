// 58 - Max Consecutive Ones | Số 1 liên tiếp nhiều nhất
// Đề: Trong dãy 0/1, tìm chuỗi số 1 liên tiếp dài nhất.
// Ràng buộc: Phần tử chỉ là 0 hoặc 1.
// Ý tưởng: Đếm chạy hiện tại, reset về 0 khi gặp số 0.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Đo chuỗi trạng thái liên tục (uptime, streak).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int findMaxConsecutiveOnes(const vector<int>& a){
    int best = 0, cur = 0;
    for (int x : a){
        cur = x ? cur + 1 : 0;
        best = max(best, cur);
    }
    return best;
}

int main(){
    // Test case
    assert(findMaxConsecutiveOnes({1, 1, 0, 1, 1, 1}) == 3);
    assert(findMaxConsecutiveOnes({0, 0}) == 0);

    cout << "OK\n";
}
