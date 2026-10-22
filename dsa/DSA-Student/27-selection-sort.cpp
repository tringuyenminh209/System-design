// 27 - Selection Sort | Sắp xếp chọn
// Đề: Sắp xếp mảng tăng dần.
// Ràng buộc: Chỉ dùng để học.
// Ý tưởng: Mỗi lượt chọn phần tử nhỏ nhất còn lại đưa lên đầu đoạn chưa sắp.
// Độ phức tạp: Time O(n^2) / Space O(1).
// Thực tế: Ít phép đổi chỗ hơn bubble sort.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> selectionSort(vector<int> a){
    int n = a.size();
    for (int i = 0; i < n; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
    return a;
}

int main(){
    // Test case
    assert((selectionSort({64, 25, 12, 22, 11}) == vector<int>{11, 12, 22, 25, 64}));

    cout << "OK\n";
}
