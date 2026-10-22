// 88 - Dijkstra | Đường đi ngắn nhất từ một đỉnh (trọng số không âm)
// Đề: Tính khoảng cách ngắn nhất từ src tới mọi đỉnh.
// Ràng buộc: Trọng số cạnh >= 0.
// Ý tưởng: Hàng đợi ưu tiên luôn lấy đỉnh gần nhất chưa xử lý để nới lỏng.
// Độ phức tạp: Time O((V + E) log V) / Space O(V).
// Thực tế: Định tuyến, bản đồ, mạng lưới.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<long long> dijkstra(int n, const vector<vector<pair<int,int>>>& adj, int src){
    vector<long long> dist(n, LLONG_MAX);
    dist[src] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u]){
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    // Test case
    vector<vector<pair<int,int>>> adj(4);
    adj[0] = {{1, 1}, {2, 4}};
    adj[1] = {{2, 2}, {3, 6}};
    adj[2] = {{3, 3}};
    auto d = dijkstra(4, adj, 0);
    assert(d[0] == 0 && d[1] == 1 && d[2] == 3 && d[3] == 6);

    cout << "OK\n";
}
