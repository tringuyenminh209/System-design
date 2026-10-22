// 100 - N-Queens | Đếm số cách đặt n hậu không ăn nhau
// Đề: Số cách đặt n quân hậu trên bàn n*n sao cho không quân nào ăn nhau.
// Ràng buộc: 1 <= n <= 12 (n lớn hơn sẽ rất chậm).
// Ý tưởng: Quay lui theo từng hàng; đánh dấu cột và hai đường chéo đã bị chiếm.
// Độ phức tạp: Time O(n!) (có cắt tỉa) / Space O(n).
// Thực tế: Mẫu backtracking kinh điển (xếp lịch, tô màu).

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: quay lui đặt hậu theo hàng
void solve(int row, int n, vector<char>& col, vector<char>& d1, vector<char>& d2, int& count){
    if (row == n){
        count++;
        return;
    }
    for (int c = 0; c < n; c++){
        int a = row + c, b = row - c + n;   // chỉ số hai đường chéo
        if (col[c] || d1[a] || d2[b])
            continue;
        col[c] = d1[a] = d2[b] = 1;
        solve(row + 1, n, col, d1, d2, count);
        col[c] = d1[a] = d2[b] = 0;         // hoàn tác (backtrack)
    }
}

// Hàm giải quyết bài toán
int totalNQueens(int n){
    vector<char> col(n, 0), d1(2 * n, 0), d2(2 * n, 0);
    int count = 0;
    solve(0, n, col, d1, d2, count);
    return count;
}

int main(){
    // Test case
    assert(totalNQueens(1) == 1);
    assert(totalNQueens(4) == 2);
    assert(totalNQueens(8) == 92);

    cout << "OK\n";
}
