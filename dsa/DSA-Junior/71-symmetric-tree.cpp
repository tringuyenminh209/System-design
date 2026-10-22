// 71 - Symmetric Tree | Cây đối xứng qua trục giữa
// Đề: Cây có đối xứng gương không?
// Ràng buộc: Cây có thể rỗng (coi là đối xứng).
// Ý tưởng: So hai nhánh ngược nhau: trái-trái với phải-phải, trái-phải với phải-trái.
// Độ phức tạp: Time O(n) / Space O(h).
// Thực tế: Đệ quy trên cặp nút, biến thể của same-tree.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm phụ: kiểm tra hai cây có phải gương của nhau
bool mirror(T* a, T* b){
    if (!a && !b)
        return true;
    if (!a || !b || a->val != b->val)
        return false;
    return mirror(a->l, b->r) && mirror(a->r, b->l);
}

// Hàm giải quyết bài toán
bool isSymmetric(T* root){
    return !root || mirror(root->l, root->r);
}

int main(){
    // Test case
    T* r = new T(1);
    r->l = new T(2);
    r->r = new T(2);
    r->l->l = new T(3);
    r->r->r = new T(3);
    assert(isSymmetric(r));
    r->r->r->val = 4;
    assert(!isSymmetric(r));

    cout << "OK\n";
}
