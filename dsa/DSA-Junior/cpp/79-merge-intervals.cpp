// 79 - Merge Intervals | Gộp các khoảng chồng lấn
// Đề: Gộp mọi khoảng [l, r] chồng nhau thành các khoảng rời.
// Ràng buộc: Khoảng cho theo cặp (đầu, cuối).
// Ý tưởng: Sắp theo đầu mút, gộp nếu khoảng mới chồng lên khoảng cuối kết quả.
// Độ phức tạp: Time O(n log n) / Space O(n).
// Thực tế: Lịch làm việc, đặt phòng, gộp khoảng thời gian.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> v){
    sort(v.begin(), v.end());
    vector<pair<int,int>> res;
    for (auto& p : v){
        if (!res.empty() && p.first <= res.back().second)
            res.back().second = max(res.back().second, p.second);
        else
            res.push_back(p);
    }
    return res;
}

int main(){
    // Test case
    vector<pair<int,int>> in = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<pair<int,int>> out = {{1, 6}, {8, 10}, {15, 18}};
    assert(mergeIntervals(in) == out);

    cout << "OK\n";
}
