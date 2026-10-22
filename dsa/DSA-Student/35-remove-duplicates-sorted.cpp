// 35 - Remove Duplicates (sorted) | Bỏ trùng trên mảng đã sắp
// Đề: Trả về mảng các giá trị duy nhất theo thứ tự.
// Ràng buộc: Mảng đầu vào đã được sắp xếp.
// Ý tưởng: So sánh với phần tử cuối của kết quả để bỏ trùng liền kề.
// Độ phức tạp: Time O(n) / Space O(1) (không kể output).
// Thực tế: Khử trùng dữ liệu đã sắp.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> removeDup(const vector<int>& a){
    vector<int> result;
    for (int x : a){
        if (result.empty() || result.back() != x)
            result.push_back(x);
    }
    return result;
}

int main(){
    // Test case
    assert((removeDup({1, 1, 2, 3, 3}) == vector<int>{1, 2, 3}));
    assert((removeDup({}) == vector<int>{}));

    cout << "OK\n";
}
