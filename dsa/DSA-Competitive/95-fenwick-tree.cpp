// 95 - Fenwick Tree (BIT) | Cây chỉ số nhị phân (tổng tiền tố + cập nhật)
// Đề: Hỗ trợ cộng dồn một phần tử và truy vấn tổng tiền tố.
// Ràng buộc: Nhiều truy vấn/cập nhật xen kẽ.
// Ý tưởng: Dùng bit thấp nhất (i & -i) để nhảy qua các đoạn quản lý.
// Độ phức tạp: Time O(log n) mỗi thao tác / Space O(n).
// Thực tế: Gọn hơn segment tree cho tổng tiền tố; đếm nghịch thế.

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Fenwick Tree (Binary Indexed Tree)
struct BIT {
    int n;
    vector<long long> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, long long v){
        for (++i; i <= n; i += i & -i)
            t[i] += v;
    }
    long long prefix(int i){
        long long s = 0;
        for (++i; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }
    long long range(int l, int r){
        return prefix(r) - (l ? prefix(l - 1) : 0);
    }
};

int main(){
    // Test case
    BIT b(6);
    vector<int> a = {1, 3, 5, 7, 9, 11};
    for (int i = 0; i < 6; i++)
        b.add(i, a[i]);
    assert(b.range(1, 3) == 15);
    b.add(1, 7);
    assert(b.range(1, 3) == 22);
    assert(b.prefix(5) == 43);

    cout << "OK\n";
}
