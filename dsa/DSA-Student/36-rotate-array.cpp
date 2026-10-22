// 36 - Rotate Array | Xoay phải k bước
// Đề: Xoay phải mảng k bước, ví dụ {1,2,3,4,5} k=2 -> {4,5,1,2,3}.
// Ràng buộc: k có thể lớn hơn n (cần k %= n).
// Ý tưởng: Đảo toàn bộ, rồi đảo hai đoạn con (reverse trick).
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Dịch vòng dữ liệu (con trỏ vòng, buffer tuần hoàn).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> rotate(vector<int> a, int k){
    int n = a.size();
    if (n == 0)
        return a;
    k %= n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    return a;
}

int main(){
    // Test case
    assert((rotate({1, 2, 3, 4, 5}, 2) == vector<int>{4, 5, 1, 2, 3}));
    assert((rotate({1, 2}, 3) == vector<int>{2, 1}));

    cout << "OK\n";
}
