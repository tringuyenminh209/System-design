// 92 - BFS Shortest Path (grid) | Đường ngắn nhất trên lưới 0/1
// Đề: Số bước ít nhất từ (0,0) tới (R-1,C-1), đi 4 hướng, ô 1 là tường; -1 nếu bí.
// Ràng buộc: Lưới không rỗng.
// Ý tưởng: BFS lan theo lớp trên đồ thị lưới không trọng số.
// Độ phức tạp: Time O(R*C) / Space O(R*C).
// Thực tế: Tìm đường mê cung, khoảng cách ngắn nhất không trọng số.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int bfsGrid(const vector<vector<int>>& g){
    int R = g.size(), C = g[0].size();
    if (g[0][0] || g[R - 1][C - 1])
        return -1;
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int,int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
    while (!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        if (r == R - 1 && c == C - 1)
            return dist[r][c];
        for (int k = 0; k < 4; k++){
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nc >= 0 && nr < R && nc < C && !g[nr][nc] && dist[nr][nc] < 0){
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main(){
    // Test case
    assert(bfsGrid({{0, 0, 0}, {1, 1, 0}, {0, 0, 0}}) == 4);
    assert(bfsGrid({{0, 1}, {1, 0}}) == -1);

    cout << "OK\n";
}
