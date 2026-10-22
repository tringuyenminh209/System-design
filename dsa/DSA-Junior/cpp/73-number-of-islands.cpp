// 73 - Number of Islands | Đếm số đảo trong lưới 0/1
// Đề: Đếm số cụm ô '1' nối nhau theo 4 hướng.
// Ràng buộc: Lưới ký tự '0'/'1' không rỗng.
// Ý tưởng: DFS/flood fill, đánh dấu ô đã thăm bằng cách đổi '1' -> '0'.
// Độ phức tạp: Time O(R*C) / Space O(R*C) (đệ quy).
// Thực tế: Đếm thành phần liên thông trên lưới (xử lý ảnh, bản đồ).

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: tô chìm cả một đảo bắt đầu từ (i, j)
void dfs(vector<vector<char>>& g, int i, int j){
    if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[0].size() || g[i][j] != '1')
        return;
    g[i][j] = '0';
    dfs(g, i + 1, j);
    dfs(g, i - 1, j);
    dfs(g, i, j + 1);
    dfs(g, i, j - 1);
}

// Hàm giải quyết bài toán
int numIslands(vector<vector<char>> g){
    int count = 0;
    for (int i = 0; i < (int)g.size(); i++){
        for (int j = 0; j < (int)g[0].size(); j++){
            if (g[i][j] == '1'){
                count++;
                dfs(g, i, j);
            }
        }
    }
    return count;
}

int main(){
    // Test case
    vector<vector<char>> g = {{'1', '1', '0', '0'}, {'1', '0', '0', '1'}, {'0', '0', '1', '1'}};
    assert(numIslands(g) == 2);

    cout << "OK\n";
}
