// 64 - Merge Two Sorted Lists | Trộn 2 danh sách liên kết đã sắp
// Đề: Gộp hai danh sách tăng dần thành một danh sách tăng dần.
// Ràng buộc: Hai danh sách đầu vào đã sắp.
// Ý tưởng: Dùng dummy head, nối dần nút nhỏ hơn ở đầu hai danh sách.
// Độ phức tạp: Time O(n + m) / Space O(1).
// Thực tế: Thao tác merge trên con trỏ; lõi của merge sort danh sách.

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút danh sách liên kết
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Hàm phụ: dựng danh sách từ vector
Node* build(const vector<int>& v){
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v){
        t->next = new Node(x);
        t = t->next;
    }
    return dummy.next;
}

// Hàm phụ: đổi danh sách về vector để kiểm tra
vector<int> toVec(Node* h){
    vector<int> r;
    for (; h; h = h->next)
        r.push_back(h->val);
    return r;
}

// Hàm giải quyết bài toán
Node* mergeTwo(Node* a, Node* b){
    Node dummy(0);
    Node* t = &dummy;
    while (a && b){
        if (a->val <= b->val){
            t->next = a;
            a = a->next;
        } else {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }
    t->next = a ? a : b;
    return dummy.next;
}

int main(){
    // Test case
    assert((toVec(mergeTwo(build({1, 2, 4}), build({1, 3, 4}))) == vector<int>{1, 1, 2, 3, 4, 4}));

    cout << "OK\n";
}
