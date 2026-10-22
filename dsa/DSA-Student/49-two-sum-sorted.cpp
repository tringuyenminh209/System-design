// 49 - Two Sum II (mảng đã sắp) | Tìm cặp có tổng target
// Đề: Mảng tăng dần, trả về chỉ số (0-based) của cặp có tổng bằng target.
// Ràng buộc: Mảng đã sắp; giả định luôn có đáp án.
// Ý tưởng: Two pointers - tổng nhỏ thì tiến trái, lớn thì lùi phải.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Khai thác thứ tự để tiết kiệm bộ nhớ so với HashMap.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
pair<int,int> twoSumSorted(const vector<int>& a, int target){
    int l = 0, r = (int)a.size() - 1;
    while (l < r){
        int sum = a[l] + a[r];
        if (sum == target)
            return {l, r};
        if (sum < target)
            l++;
        else
            r--;
    }
    return {-1, -1};
}

int main(){
    // Test case
    assert(twoSumSorted({2, 7, 11, 15}, 9) == make_pair(0, 1));
    assert(twoSumSorted({2, 3, 4}, 6) == make_pair(0, 2));

    cout << "OK\n";
}
