// 62 - Middle of Linked List | Nút giữa danh sách
// Đề: Trả về nút giữa; nếu số nút chẵn thì lấy nút giữa thứ hai.
// Ràng buộc: Danh sách không rỗng.
// Ý tưởng: Con trỏ slow đi 1 bước, fast đi 2 bước; fast tới cuối thì slow ở giữa.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Kỹ thuật con trỏ nhanh-chậm (fast/slow pointers).

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

// Hàm giải quyết bài toán
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    // Test case
    assert(middleNode(build({1, 2, 3, 4, 5}))->val == 3);
    assert(middleNode(build({1, 2, 3, 4, 5, 6}))->val == 4);

    cout << "OK\n";
}
