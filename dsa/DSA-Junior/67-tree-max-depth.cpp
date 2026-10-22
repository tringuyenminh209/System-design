// 67 - Max Depth of Binary Tree | Chiều sâu lớn nhất
// Đề: Số nút trên đường dài nhất từ gốc tới lá.
// Ràng buộc: Cây có thể rỗng (độ sâu 0).
// Ý tưởng: Đệ quy - độ sâu = 1 + max(độ sâu trái, độ sâu phải).
// Độ phức tạp: Time O(n) / Space O(h).
// Thực tế: Đo độ cao cây, nền tảng nhiều bài về cây.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm giải quyết bài toán
int maxDepth(T* n){
    if (!n)
        return 0;
    return 1 + max(maxDepth(n->l), maxDepth(n->r));
}

int main(){
    // Test case
    T* root = new T(3);
    root->l = new T(9);
    root->r = new T(20);
    root->r->l = new T(15);
    root->r->r = new T(7);
    assert(maxDepth(root) == 3);
    assert(maxDepth(nullptr) == 0);

    cout << "OK\n";
}
