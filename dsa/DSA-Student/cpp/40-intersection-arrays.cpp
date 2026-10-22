// 40 - Intersection of Arrays | Giao hai mảng (giá trị duy nhất)
// Đề: Trả về các giá trị có ở cả hai mảng, mỗi giá trị một lần, đã sắp.
// Ràng buộc: 0 <= n, m <= 1e5.
// Ý tưởng: Đưa mảng a vào set, lọc các phần tử của b thuộc set đó.
// Độ phức tạp: Time O(n + m) / Space O(n).
// Thực tế: So khớp hai tập dữ liệu.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> intersection(const vector<int>& a, const vector<int>& b){
    set<int> sa(a.begin(), a.end());
    set<int> result;
    for (int x : b){
        if (sa.count(x))
            result.insert(x);
    }
    return vector<int>(result.begin(), result.end());
}

int main(){
    // Test case
    assert((intersection({1, 2, 2, 1}, {2, 2}) == vector<int>{2}));
    assert((intersection({4, 9, 5}, {9, 4, 9, 8, 4}) == vector<int>{4, 9}));

    cout << "OK\n";
}
