// 78 - Jump Game | Có tới được ô cuối không
// Đề: Mỗi ô cho bước nhảy tối đa a[i]; xuất phát ô 0, có tới ô cuối?
// Ràng buộc: Phần tử >= 0.
// Ý tưởng: Greedy - theo dõi chỉ số xa nhất "reach" có thể tới.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Tư duy tham lam, cập nhật tầm với tối đa.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool canJump(const vector<int>& a){
    int reach = 0;
    for (int i = 0; i < (int)a.size(); i++){
        if (i > reach)
            return false;
        reach = max(reach, i + a[i]);
    }
    return true;
}

int main(){
    // Test case
    assert(canJump({2, 3, 1, 1, 4}));
    assert(!canJump({3, 2, 1, 0, 4}));
    assert(canJump({0}));

    cout << "OK\n";
}
