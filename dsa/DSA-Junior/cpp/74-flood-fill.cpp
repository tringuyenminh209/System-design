// 74 - Flood Fill | Tô màu vùng liên thông
// Đề: Từ ô (sr, sc), đổi mọi ô cùng màu nối nhau sang màu mới.
// Ràng buộc: Lưới không rỗng.
// Ý tưởng: DFS lan theo 4 hướng khi ô có màu gốc.
// Độ phức tạp: Time O(R*C) / Space O(R*C).
// Thực tế: Công cụ "xô sơn" trong ứng dụng vẽ; loang trên lưới.

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: DFS đổi màu
void fill(vector<vector<int>>& g, int i, int j, int oldC, int newC){
    if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[0].size() || g[i][j] != oldC)
        return;
    g[i][j] = newC;
    fill(g, i + 1, j, oldC, newC);
    fill(g, i - 1, j, oldC, newC);
    fill(g, i, j + 1, oldC, newC);
    fill(g, i, j - 1, oldC, newC);
}

// Hàm giải quyết bài toán
vector<vector<int>> floodFill(vector<vector<int>> g, int sr, int sc, int newC){
    if (g[sr][sc] != newC)
        fill(g, sr, sc, g[sr][sc], newC);
    return g;
}

int main(){
    // Test case
    vector<vector<int>> g = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    auto r = floodFill(g, 1, 1, 2);
    assert((r == vector<vector<int>>{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}));

    cout << "OK\n";
}
