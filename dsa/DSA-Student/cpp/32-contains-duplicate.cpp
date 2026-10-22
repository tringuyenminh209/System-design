// 32 - Contains Duplicate | Có phần tử trùng không?
// Đề: Trả về true nếu tồn tại giá trị xuất hiện >= 2 lần.
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Dùng set để phát hiện trùng khi duyệt.
// Độ phức tạp: Time O(n) / Space O(n).
// Thực tế: Kiểm tra tính duy nhất (email, mã) trước khi lưu.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool containsDuplicate(const vector<int>& a){
    unordered_set<int> seen;
    for (int x : a){
        if (seen.count(x))
            return true;
        seen.insert(x);
    }
    return false;
}

int main(){
    // Test case
    assert(containsDuplicate({1, 2, 3, 1}));
    assert(!containsDuplicate({1, 2, 3, 4}));
    assert(!containsDuplicate({}));

    cout << "OK\n";
}
