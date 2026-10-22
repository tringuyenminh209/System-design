// 61 - Reverse Linked List | Đảo ngược danh sách liên kết
// Đề: Đảo chiều các con trỏ next của danh sách.
// Ràng buộc: Danh sách có thể rỗng.
// Ý tưởng: Ba con trỏ prev/cur/next, đảo chiều dần từng nút.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Thao tác con trỏ nền tảng; hay hỏi khi phỏng vấn.

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
Node* reverseList(Node* head){
    Node* prev = nullptr;
    while (head){
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

int main(){
    // Test case
    assert((toVec(reverseList(build({1, 2, 3, 4, 5}))) == vector<int>{5, 4, 3, 2, 1}));
    assert(reverseList(nullptr) == nullptr);

    cout << "OK\n";
}
