// 16 - Average | Trung bình cộng
// Đề: Trả về trung bình cộng (kiểu double) của mảng.
// Ràng buộc: Mảng không rỗng (n >= 1).
// Ý tưởng: Tổng các phần tử chia cho số lượng.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Thống kê cơ bản; chú ý ép kiểu để không chia số nguyên.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
double average(const vector<int>& a){
    double sum = 0;
    for (int x : a)
        sum += x;
    return sum / a.size();
}

int main(){
    // Test case
    assert(average({1, 2, 3, 4}) == 2.5);
    assert(average({5}) == 5.0);

    cout << "OK\n";
}
