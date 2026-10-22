// 26 - Bubble Sort | Sắp xếp nổi bọt
// Đề: Sắp xếp mảng tăng dần.
// Ràng buộc: Chỉ dùng để học (chậm với n lớn).
// Ý tưởng: Đổi chỗ cặp kề sai thứ tự; dừng sớm nếu một lượt không có đổi chỗ.
// Độ phức tạp: Time O(n^2) / Space O(1).
// Thực tế: Dễ hiểu nhưng ít dùng thực chiến; nền tảng hiểu về sắp xếp.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> bubbleSort(vector<int> a){
    int n = a.size();
    for (int i = 0; i < n - 1; i++){
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return a;
}

int main(){
    // Test case
    assert((bubbleSort({5, 2, 4, 1, 3}) == vector<int>{1, 2, 3, 4, 5}));
    assert((bubbleSort({}) == vector<int>{}));

    cout << "OK\n";
}
