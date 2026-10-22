// 69 - Invert Binary Tree | Lật gương cây nhị phân
// Đề: Đổi chỗ con trái và con phải ở mọi nút.
// Ràng buộc: Cây có thể rỗng.
// Ý tưởng: Đệ quy hoán đổi hai con rồi lật tiếp hai cây con.
// Độ phức tạp: Time O(n) / Space O(h).
// Thực tế: Bài phỏng vấn nổi tiếng; thao tác đệ quy trên cây.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm phụ: duyệt inorder để kiểm tra
void inorder(T* n, vector<int>& o){
    if (!n)
        return;
    inorder(n->l, o);
    o.push_back(n->val);
    inorder(n->r, o);
}

// Hàm giải quyết bài toán
T* invert(T* n){
    if (!n)
        return nullptr;
    swap(n->l, n->r);
    invert(n->l);
    invert(n->r);
    return n;
}

int main(){
    // Test case
    T* root = new T(4);
    root->l = new T(2);
    root->r = new T(7);
    invert(root);
    vector<int> o;
    inorder(root, o);
    assert((o == vector<int>{7, 4, 2}));

    cout << "OK\n";
}
