// 34 - Move Zeroes | Dồn số 0 về cuối
// Đề: Chuyển mọi số 0 về cuối, giữ nguyên thứ tự các số khác.
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Con trỏ ghi j - dồn các số khác 0 lên trước, phần còn lại điền 0.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Nén dữ liệu, loại bỏ giá trị rỗng tại chỗ.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> moveZeroes(vector<int> a){
    int j = 0;
    for (int x : a){
        if (x != 0)
            a[j++] = x;
    }
    while (j < (int)a.size())
        a[j++] = 0;
    return a;
}

int main(){
    // Test case
    assert((moveZeroes({0, 1, 0, 3, 12}) == vector<int>{1, 3, 12, 0, 0}));
    assert((moveZeroes({0, 0}) == vector<int>{0, 0}));

    cout << "OK\n";
}
