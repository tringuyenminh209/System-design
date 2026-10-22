// 66 - Binary Tree Inorder | Duyệt cây nhị phân theo thứ tự giữa
// Đề: Trả về danh sách giá trị theo thứ tự trái - gốc - phải.
// Ràng buộc: Cây có thể rỗng.
// Ý tưởng: Đệ quy duyệt trái, thăm gốc, rồi duyệt phải.
// Độ phức tạp: Time O(n) / Space O(h) (chiều cao cây).
// Thực tế: Với cây tìm kiếm nhị phân, inorder cho dãy tăng dần.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm giải quyết bài toán
void inorder(T* n, vector<int>& out){
    if (!n)
        return;
    inorder(n->l, out);
    out.push_back(n->val);
    inorder(n->r, out);
}

int main(){
    // Test case
    T* root = new T(1);
    root->r = new T(2);
    root->r->l = new T(3);
    vector<int> out;
    inorder(root, out);
    assert((out == vector<int>{1, 3, 2}));

    cout << "OK\n";
}
