// 97 - Trie | Cây tiền tố (insert / search / startsWith)
// Đề: Cấu trúc lưu tập chuỗi, hỗ trợ thêm, tìm chính xác và tìm theo tiền tố.
// Ràng buộc: Chuỗi gồm chữ thường a-z.
// Ý tưởng: Mỗi nút có 26 con theo chữ cái; đánh dấu nút kết thúc từ.
// Độ phức tạp: Time O(độ dài từ) mỗi thao tác / Space O(tổng ký tự).
// Thực tế: Gợi ý gõ, autocomplete, kiểm tra tiền tố.

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Trie (cây tiền tố)
struct Trie {
    struct Node {
        Node* ch[26] = {};
        bool end = false;
    };
    Node* root = new Node();

    void insert(const string& w){
        Node* n = root;
        for (char c : w){
            int i = c - 'a';
            if (!n->ch[i])
                n->ch[i] = new Node();
            n = n->ch[i];
        }
        n->end = true;
    }
    Node* walk(const string& w){
        Node* n = root;
        for (char c : w){
            int i = c - 'a';
            if (!n->ch[i])
                return nullptr;
            n = n->ch[i];
        }
        return n;
    }
    bool search(const string& w){
        Node* n = walk(w);
        return n && n->end;
    }
    bool startsWith(const string& p){
        return walk(p) != nullptr;
    }
};

int main(){
    // Test case
    Trie t;
    t.insert("apple");
    assert(t.search("apple"));
    assert(!t.search("app"));
    assert(t.startsWith("app"));
    assert(!t.startsWith("bpp"));

    cout << "OK\n";
}
