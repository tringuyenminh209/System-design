// 90 - Union-Find (DSU) | Cấu trúc hợp-tìm
// Đề: Đếm số thành phần liên thông sau các phép hợp.
// Ràng buộc: Số phần tử n cho trước.
// Ý tưởng: Cây đại diện với nén đường (path compression) và hợp theo hạng (union by rank).
// Độ phức tạp: Gần O(1) khấu hao mỗi thao tác.
// Thực tế: Nhóm phần tử, thuật toán Kruskal, kết nối mạng.

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Union-Find
struct DSU {
    vector<int> parent, rank_;
    int comp;
    DSU(int n) : parent(n), rank_(n, 0), comp(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
        comp--;
    }
};

int main(){
    // Test case
    DSU d(5);
    d.unite(0, 1);
    d.unite(1, 2);
    d.unite(3, 4);
    assert(d.comp == 2);
    assert(d.find(0) == d.find(2));
    assert(d.find(0) != d.find(3));

    cout << "OK\n";
}
