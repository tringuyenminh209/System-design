// 28 - Insertion Sort | Sắp xếp chèn
// Đề: Sắp xếp mảng tăng dần.
// Ràng buộc: Hiệu quả với dữ liệu nhỏ hoặc gần như đã sắp.
// Ý tưởng: Chèn từng phần tử vào đúng vị trí trong phần đã sắp phía trước.
// Độ phức tạp: Time O(n^2), tốt nhất O(n) / Space O(1).
// Thực tế: Nhanh cho mảng nhỏ; dùng trong các thư viện sort lai.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> insertionSort(vector<int> a){
    for (int i = 1; i < (int)a.size(); i++){
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return a;
}

int main(){
    // Test case
    assert((insertionSort({5, 2, 4, 6, 1, 3}) == vector<int>{1, 2, 3, 4, 5, 6}));

    cout << "OK\n";
}
