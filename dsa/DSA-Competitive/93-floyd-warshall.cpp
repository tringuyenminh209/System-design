// 93 - Floyd-Warshall | Đường ngắn nhất giữa mọi cặp đỉnh
// Đề: Tính ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh.
// Ràng buộc: Đồ thị nhỏ (V <= vài trăm); không có chu trình âm.
// Ý tưởng: DP qua đỉnh trung gian k - thử đường i -> k -> j.
// Độ phức tạp: Time O(V^3) / Space O(V^2).
// Thực tế: Đồ thị nhỏ cần khoảng cách mọi cặp; cài đặt ngắn gọn.

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Hàm giải quyết bài toán
vector<vector<long long>> floyd(vector<vector<long long>> d){
    int n = d.size();
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

int main(){
    // Test case
    vector<vector<long long>> d = {{0, 3, INF, 7}, {8, 0, 2, INF}, {5, INF, 0, 1}, {2, INF, INF, 0}};
    auto r = floyd(d);
    assert(r[0][2] == 5 && r[0][3] == 6 && r[3][1] == 5);

    cout << "OK\n";
}
