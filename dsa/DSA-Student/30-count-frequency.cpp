// 30 - Count Frequency | Đếm tần suất mỗi giá trị
// Đề: Trả về map giá_trị -> số_lần xuất hiện.
// Ràng buộc: 0 <= n <= 1e5.
// Ý tưởng: Dùng map cộng dồn khi duyệt.
// Độ phức tạp: Time O(n log n) với map (O(n) nếu hash) / Space O(n).
// Thực tế: Thống kê, tìm phần tử phổ biến, tiền đề nhiều bài khác.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
map<int,int> countFreq(const vector<int>& a){
    map<int,int> freq;
    for (int x : a)
        freq[x]++;
    return freq;
}

int main(){
    // Test case
    auto f = countFreq({1, 1, 2, 3, 3, 3});
    assert(f[1] == 2 && f[2] == 1 && f[3] == 3);
    assert(countFreq({}).empty());

    cout << "OK\n";
}
