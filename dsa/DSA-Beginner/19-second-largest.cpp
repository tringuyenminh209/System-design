// 19 - Second Largest | Phần tử lớn nhì (phân biệt giá trị)
// Ngôn ngữ: C++
// Đề: Trả về giá trị lớn thứ hai, -1 nếu không tồn tại.
// Ràng buộc: Giá trị lớn nhì phải KHÁC giá trị lớn nhất.
// Ý tưởng: Giữ hai biến largest và second, cập nhật khi gặp giá trị mới.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Xếp hạng, tìm á quân.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int secondLargest(const vector<int>& a){
    // LLONG_MIN: giá trị long long nhỏ nhất, làm mốc "chưa có" (nhỏ hơn mọi int thật)
    long long best1 = LLONG_MIN, best2 = LLONG_MIN; // best1 = lớn nhất, best2 = lớn nhì
    for (int x : a){
        if (x > best1){                 // x vượt lớn nhất -> best1 cũ tụt xuống làm best2
            best2 = best1;
            best1 = x;
        } else if (x < best1 && x > best2){ // x < best1 để loại giá trị TRÙNG lớn nhất
            best2 = x;
        }
    }
    return best2 == LLONG_MIN ? -1 : (int)best2; // vẫn là mốc -> không tồn tại lớn nhì
}

int main(){
    // Test case
    assert(secondLargest({3, 1, 4, 1, 5}) == 4);
    assert(secondLargest({5, 5, 4}) == 4);
    assert(secondLargest({7, 7, 7}) == -1);

    cout << "OK\n";
}
