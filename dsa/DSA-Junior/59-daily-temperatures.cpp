// 59 - Daily Temperatures | Số ngày chờ đến ngày ấm hơn
// Đề: Với mỗi ngày, sau bao nhiêu ngày thì nhiệt độ cao hơn (0 nếu không có).
// Ràng buộc: 1 <= n <= 1e5.
// Ý tưởng: Monotonic stack lưu chỉ số các ngày có nhiệt độ giảm dần.
// Độ phức tạp: Time O(n) / Space O(n).
// Thực tế: Mẫu next-greater dạng khoảng cách.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> dailyTemperatures(const vector<int>& t){
    int n = t.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && t[i] > t[st.top()]){
            res[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main(){
    // Test case
    assert((dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) == vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));

    cout << "OK\n";
}
