// 72 - Path Sum | Có đường gốc-tới-lá tổng bằng target?
// Đề: Tồn tại đường từ gốc tới lá có tổng giá trị = target?
// Ràng buộc: Cây có thể rỗng (trả về false).
// Ý tưởng: Đệ quy trừ dần target; tại lá kiểm tra phần còn lại.
// Độ phức tạp: Time O(n) / Space O(h).
// Thực tế: Duyệt cây kèm trạng thái tích lũy.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm giải quyết bài toán
bool hasPathSum(T* n, int target){
    if (!n)
        return false;
    if (!n->l && !n->r)
        return target == n->val;
    return hasPathSum(n->l, target - n->val) || hasPathSum(n->r, target - n->val);
}

int main(){
    // Test case
    T* r = new T(5);
    r->l = new T(4);
    r->r = new T(8);
    r->l->l = new T(11);
    r->l->l->l = new T(7);
    r->l->l->r = new T(2);
    assert(hasPathSum(r, 22));
    assert(!hasPathSum(r, 100));

    cout << "OK\n";
}
