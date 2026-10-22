// 02 - Max Element | Phần tử lớn nhất
// Đề: Trả về phần tử lớn nhất của mảng.
// Ràng buộc: Mảng không rỗng (n >= 1).
// Ý tưởng: Giữ biến max, duyệt một lần và cập nhật.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Tìm giá trị đỉnh (doanh thu cao nhất, điểm cao nhất).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int maxElement(const vector<int>& a){
    int m = a[0];
    for (int x : a)
        m = max(m, x);
    return m;
}

int main(){
    // Test case
    assert(maxElement({3, 7, 2, 9, 4}) == 9);
    assert(maxElement({-5, -2, -9}) == -2);
    assert(maxElement({42}) == 42);

    cout << "OK\n";
}
