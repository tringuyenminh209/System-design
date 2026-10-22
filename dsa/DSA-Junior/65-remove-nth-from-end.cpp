// 65 - Remove Nth From End | Xóa nút thứ n từ cuối
// Đề: Xóa nút thứ n tính từ cuối (n >= 1) và trả về đầu danh sách.
// Ràng buộc: 1 <= n <= độ dài danh sách.
// Ý tưởng: Hai con trỏ cách nhau n bước, dùng dummy để xử lý xóa nút đầu.
// Độ phức tạp: Time O(n) / Space O(1) (một lượt duyệt).
// Thực tế: Khoảng cách cố định giữa hai con trỏ.

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
Node* removeNth(Node* head, int n){
    Node dummy(0);
    dummy.next = head;
    Node* fast = &dummy;
    Node* slow = &dummy;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    while (fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
}

int main(){
    // Test case
    assert((toVec(removeNth(build({1, 2, 3, 4, 5}), 2)) == vector<int>{1, 2, 3, 5}));
    assert((toVec(removeNth(build({1}), 1)) == vector<int>{}));

    cout << "OK\n";
}
