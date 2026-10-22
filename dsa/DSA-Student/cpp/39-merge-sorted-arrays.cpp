// 39 - Merge Two Sorted Arrays | Trộn 2 mảng đã sắp
// Đề: Trộn hai mảng tăng dần thành một mảng tăng dần.
// Ràng buộc: Cả hai mảng đầu vào đã được sắp.
// Ý tưởng: Two pointers so đầu hai mảng, chọn nhỏ hơn đưa vào kết quả.
// Độ phức tạp: Time O(n + m) / Space O(n + m).
// Thực tế: Bước merge trong Merge Sort, gộp dữ liệu đã sắp.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> merge(const vector<int>& a, const vector<int>& b){
    vector<int> result;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()){
        if (a[i] <= b[j])
            result.push_back(a[i++]);
        else
            result.push_back(b[j++]);
    }
    while (i < (int)a.size())
        result.push_back(a[i++]);
    while (j < (int)b.size())
        result.push_back(b[j++]);
    return result;
}

int main(){
    // Test case
    assert((merge({1, 3, 5}, {2, 4, 6}) == vector<int>{1, 2, 3, 4, 5, 6}));
    assert((merge({}, {1, 2}) == vector<int>{1, 2}));

    cout << "OK\n";
}
