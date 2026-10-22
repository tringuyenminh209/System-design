// 94 - Segment Tree | Cây phân đoạn (tổng đoạn + cập nhật điểm)
// Đề: Hỗ trợ cập nhật một phần tử và truy vấn tổng đoạn [l, r].
// Ràng buộc: Nhiều truy vấn/cập nhật xen kẽ.
// Ý tưởng: Cây nhị phân, mỗi nút giữ tổng của một đoạn; cài đặt lặp (iterative).
// Độ phức tạp: Time O(log n) mỗi thao tác / Space O(n).
// Thực tế: Truy vấn/cập nhật xen kẽ trên mảng động (bảng xếp hạng, thống kê).

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Segment Tree (iterative)
struct SegTree {
    int n;
    vector<long long> t;
    SegTree(const vector<int>& a){
        n = a.size();
        t.assign(2 * n, 0);
        for (int i = 0; i < n; i++)
            t[n + i] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[2 * i] + t[2 * i + 1];
    }
    void update(int i, long long val){
        for (t[i += n] = val; i > 1; i >>= 1)
            t[i >> 1] = t[i] + t[i ^ 1];
    }
    long long query(int l, int r){   // tổng đoạn [l, r]
        long long s = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
            if (l & 1) s += t[l++];
            if (r & 1) s += t[--r];
        }
        return s;
    }
};

int main(){
    // Test case
    SegTree st({1, 3, 5, 7, 9, 11});
    assert(st.query(1, 3) == 15);
    st.update(1, 10);
    assert(st.query(1, 3) == 22);
    assert(st.query(0, 5) == 43);

    cout << "OK\n";
}
