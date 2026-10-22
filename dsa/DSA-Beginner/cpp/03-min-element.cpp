// 03 - Min Element | Phần tử nhỏ nhất
// Đề: Trả về phần tử nhỏ nhất của mảng.
// Ràng buộc: Mảng không rỗng (n >= 1).
// Ý tưởng: Giữ biến min, duyệt một lần và cập nhật.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Tìm giá trị thấp nhất (giá rẻ nhất, nhiệt độ thấp nhất).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int minElement(const vector<int>& a){
    int m = a[0];
    for (int x : a)
        m = min(m, x);
    return m;
}

int main(){
    // Test case
    assert(minElement({3, 7, 2, 9, 4}) == 2);
    assert(minElement({-5, -2, -9}) == -9);
    assert(minElement({42}) == 42);

    cout << "OK\n";
}
