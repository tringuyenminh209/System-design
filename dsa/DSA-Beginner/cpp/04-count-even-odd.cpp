// 04 - Count Even/Odd | Đếm số chẵn và lẻ
// Đề: Trả về cặp (số chẵn, số lẻ) trong mảng.
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Duyệt mảng, kiểm tra x % 2 để phân loại.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Phân loại dữ liệu theo tính chất.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
pair<int,int> countEvenOdd(const vector<int>& a){
    int even = 0, odd = 0;
    for (int x : a){
        if (x % 2 == 0) even++;
        else odd++;
    }
    return {even, odd};
}

int main(){
    // Test case
    assert(countEvenOdd({1, 2, 3, 4, 5}) == make_pair(2, 3));
    assert(countEvenOdd({2, 4, 6}) == make_pair(3, 0));

    cout << "OK\n";
}
