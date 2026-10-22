// 91 - Kruskal MST | Cây khung nhỏ nhất
// Đề: Tổng trọng số cây khung nhỏ nhất của đồ thị vô hướng liên thông.
// Ràng buộc: Đồ thị liên thông, trọng số bất kỳ.
// Ý tưởng: Sắp cạnh tăng dần, thêm cạnh nếu không tạo chu trình (dùng DSU).
// Độ phức tạp: Time O(E log E) / Space O(V).
// Thực tế: Nối mạng/đường ống với chi phí thấp nhất.

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Union-Find rút gọn
struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        parent[a] = b;
        return true;
    }
};

// Hàm giải quyết bài toán
int kruskal(int n, vector<tuple<int,int,int>> edges){
    sort(edges.begin(), edges.end());  // theo trọng số (phần tử đầu tuple)
    DSU dsu(n);
    int total = 0;
    for (auto [w, u, v] : edges){
        if (dsu.unite(u, v))
            total += w;
    }
    return total;
}

int main(){
    // Test case
    assert(kruskal(4, {{1, 0, 1}, {4, 0, 2}, {2, 1, 2}, {6, 1, 3}, {3, 2, 3}}) == 6);

    cout << "OK\n";
}
