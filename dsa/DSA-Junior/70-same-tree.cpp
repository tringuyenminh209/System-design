// 70 - Same Tree | Hai cây có giống nhau không
// Đề: Hai cây giống hệt về cấu trúc và giá trị?
// Ràng buộc: Cây có thể rỗng.
// Ý tưởng: Đệ quy so song song gốc và hai cây con tương ứng.
// Độ phức tạp: Time O(n) / Space O(h).
// Thực tế: So sánh cấu trúc dữ liệu cây.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm giải quyết bài toán
bool sameTree(T* a, T* b){
    if (!a && !b)
        return true;
    if (!a || !b || a->val != b->val)
        return false;
    return sameTree(a->l, b->l) && sameTree(a->r, b->r);
}

int main(){
    // Test case
    T* a = new T(1);
    a->l = new T(2);
    T* b = new T(1);
    b->l = new T(2);
    assert(sameTree(a, b));
    T* c = new T(1);
    c->r = new T(2);
    assert(!sameTree(a, c));

    cout << "OK\n";
}
