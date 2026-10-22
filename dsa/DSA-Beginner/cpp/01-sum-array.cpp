// 01 - Sum Array | Tổng các phần tử mảng
// Đề: Cho mảng số nguyên, trả về tổng các phần tử.
// Ràng buộc: 1 <= n <= 1e5; mảng có thể rỗng (tổng = 0).
// Ý tưởng: Cộng dồn một lần duyệt.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Nền tảng của mọi phép tổng hợp dữ liệu (thống kê, báo cáo).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
long long sumArray(const vector<int>& a){
    long long sum = 0;
    for (int x : a)
        sum += x;
    return sum;
}

int main(){
    // Test case
    assert(sumArray({1, 2, 3, 4}) == 10);
    assert(sumArray({}) == 0);
    assert(sumArray({-1, 1}) == 0);

    cout << "OK\n";
}
