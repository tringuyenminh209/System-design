// 80 - Minimum Meeting Rooms | Số phòng họp tối thiểu
// Đề: Cho các cuộc họp [start, end); cần ít nhất bao nhiêu phòng để không trùng.
// Ràng buộc: end > start.
// Ý tưởng: Coi start là +1, end là -1; sắp theo thời gian, đếm chồng lấn tối đa.
// Độ phức tạp: Time O(n log n) / Space O(n).
// Thực tế: Lập lịch tài nguyên (phòng họp, CPU, làn đường).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int minMeetingRooms(vector<pair<int,int>> meetings){
    vector<pair<int,int>> events;
    for (auto& p : meetings){
        events.push_back({p.first, 1});
        events.push_back({p.second, -1});
    }
    sort(events.begin(), events.end());
    int cur = 0, best = 0;
    for (auto& e : events){
        cur += e.second;
        best = max(best, cur);
    }
    return best;
}

int main(){
    // Test case
    assert(minMeetingRooms({{0, 30}, {5, 10}, {15, 20}}) == 2);
    assert(minMeetingRooms({{7, 10}, {2, 4}}) == 1);

    cout << "OK\n";
}
