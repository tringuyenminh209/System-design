// 18 - Linear Search | Tìm kiếm tuyến tính
// Ngôn ngữ: C++
// Đề: Trả về chỉ số đầu tiên của target, -1 nếu không tồn tại.
// Ràng buộc: Mảng chưa cần sắp xếp.
// Ý tưởng: Duyệt tuần tự và so sánh từng phần tử.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Dùng khi dữ liệu nhỏ hoặc chưa được sắp xếp.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int search(const vector<int>& a, int target){
    // a.size(): số phần tử của vector; ép (int) để so sánh an toàn với i
    for (int i = 0; i < (int)a.size(); i++){
        if (a[i] == target)
            return i;                   // gặp là trả về ngay -> luôn ra chỉ số ĐẦU TIÊN
    }
    return -1;                          // duyệt hết không thấy
}

int main(){
    // Test case
    assert(search({4, 2, 7, 1}, 7) == 2);
    assert(search({4, 2, 7, 1}, 9) == -1);
    assert(search({}, 1) == -1);

    cout << "OK\n";
}
