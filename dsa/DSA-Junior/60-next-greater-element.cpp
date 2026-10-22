// 60 - Next Greater Element | Phần tử lớn hơn kế tiếp bên phải
// Đề: Với mỗi phần tử, tìm giá trị lớn hơn đầu tiên ở bên phải (-1 nếu không có).
// Ràng buộc: 1 <= n <= 1e5.
// Ý tưởng: Monotonic stack lưu chỉ số các phần tử chưa tìm được "lớn hơn".
// Độ phức tạp: Time O(n) / Space O(n).
// Thực tế: Mẫu next-greater kinh điển (giá cổ phiếu, nhiệt độ).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> nextGreater(const vector<int>& a){
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && a[i] > a[st.top()]){
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main(){
    // Test case
    assert((nextGreater({2, 1, 2, 4, 3}) == vector<int>{4, 2, 4, -1, -1}));

    cout << "OK\n";
}
