// 45 - Plus One | Cộng 1 vào số biểu diễn bằng mảng chữ số
// Đề: Mảng chữ số (đầu là hàng cao nhất) + 1, ví dụ {1,2,3}->{1,2,4}, {9,9}->{1,0,0}.
// Ràng buộc: Mỗi phần tử là chữ số 0..9.
// Ý tưởng: Cộng từ cuối, xử lý nhớ; nếu nhớ vượt đầu thì chèn 1 lên đầu.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Cộng số lớn vượt kiểu nguyên (big number).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
vector<int> plusOne(vector<int> d){
    for (int i = (int)d.size() - 1; i >= 0; i--){
        if (d[i] < 9){
            d[i]++;
            return d;
        }
        d[i] = 0;
    }
    d.insert(d.begin(), 1);
    return d;
}

int main(){
    // Test case
    assert((plusOne({1, 2, 3}) == vector<int>{1, 2, 4}));
    assert((plusOne({9, 9}) == vector<int>{1, 0, 0}));

    cout << "OK\n";
}
