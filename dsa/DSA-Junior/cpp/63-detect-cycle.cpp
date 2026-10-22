// 63 - Detect Cycle | Phát hiện chu trình trong danh sách liên kết
// Đề: Danh sách có vòng lặp không.
// Ràng buộc: Danh sách có thể rỗng hoặc có vòng.
// Ý tưởng: Floyd - slow đi 1, fast đi 2; nếu gặp nhau thì có vòng.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Phát hiện lặp vô hạn; "thuật toán rùa và thỏ".

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nút danh sách liên kết
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Hàm giải quyết bài toán
bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main(){
    // Test case
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next = b;
    b->next = c;
    assert(!hasCycle(a));
    c->next = a;            // tạo vòng
    assert(hasCycle(a));

    cout << "OK\n";
}
