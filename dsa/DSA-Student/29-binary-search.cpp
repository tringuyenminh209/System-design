// 29 - Binary Search | Tìm kiếm nhị phân
// Đề: Trên mảng đã sắp tăng, trả về chỉ số target, -1 nếu không có.
// Ràng buộc: Mảng phải được sắp xếp trước.
// Ý tưởng: Chia đôi khoảng tìm kiếm dựa vào so sánh với phần tử giữa.
// Độ phức tạp: Time O(log n) / Space O(1).
// Thực tế: Nền tảng tra cứu nhanh trên dữ liệu đã sắp.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int binarySearch(const vector<int>& a, int target){
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main(){
    // Test case
    assert(binarySearch({1, 3, 5, 7, 9}, 7) == 3);
    assert(binarySearch({1, 3, 5, 7, 9}, 4) == -1);
    assert(binarySearch({}, 1) == -1);

    cout << "OK\n";
}
