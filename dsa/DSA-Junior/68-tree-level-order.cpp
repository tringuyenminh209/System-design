// 68 - Binary Tree Level Order | Duyệt theo tầng (BFS)
// Đề: Trả về giá trị theo từng tầng từ trên xuống dưới.
// Ràng buộc: Cây có thể rỗng.
// Ý tưởng: BFS dùng queue, xử lý trọn một tầng mỗi vòng lặp.
// Độ phức tạp: Time O(n) / Space O(n).
// Thực tế: BFS trên cây; nền tảng duyệt theo mức.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút cây nhị phân
struct T {
    int val;
    T *l, *r;
    T(int v) : val(v), l(nullptr), r(nullptr) {}
};

// Hàm giải quyết bài toán
vector<vector<int>> levelOrder(T* root){
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<T*> q;
    q.push(root);
    while (!q.empty()){
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++){
            T* n = q.front();
            q.pop();
            level.push_back(n->val);
            if (n->l) q.push(n->l);
            if (n->r) q.push(n->r);
        }
        res.push_back(level);
    }
    return res;
}

int main(){
    // Test case
    T* root = new T(3);
    root->l = new T(9);
    root->r = new T(20);
    root->r->l = new T(15);
    root->r->r = new T(7);
    auto r = levelOrder(root);
    assert((r == vector<vector<int>>{{3}, {9, 20}, {15, 7}}));

    cout << "OK\n";
}
