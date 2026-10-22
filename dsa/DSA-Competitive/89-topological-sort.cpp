// 89 - Topological Sort | Sắp xếp topo (Kahn) trên DAG
// Đề: Trả về một thứ tự sao cho mọi cạnh u->v thì u đứng trước v.
// Ràng buộc: Đồ thị có hướng, không chu trình (DAG).
// Ý tưởng: Kahn - lặp lấy đỉnh có bậc vào 0 (dùng min-heap cho kết quả xác định).
// Độ phức tạp: Time O((V + E) log V) / Space O(V + E).
// Thực tế: Lập lịch phụ thuộc (build, khóa học tiên quyết).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> topoSort(int n, const vector<pair<int,int>>& edges){
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto [u, v] : edges){
        adj[u].push_back(v);
        indeg[v]++;
    }
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; i++){
        if (!indeg[i])
            q.push(i);
    }
    vector<int> order;
    while (!q.empty()){
        int u = q.top();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]){
            if (--indeg[v] == 0)
                q.push(v);
        }
    }
    return order;
}

int main(){
    // Test case
    auto o = topoSort(6, {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}});
    vector<int> pos(6);
    for (int i = 0; i < 6; i++)
        pos[o[i]] = i;
    assert(o.size() == 6);
    assert(pos[5] < pos[2] && pos[2] < pos[3] && pos[3] < pos[1] && pos[4] < pos[0]);

    cout << "OK\n";
}
