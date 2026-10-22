// 31 - First Unique Char | Ký tự đầu tiên không lặp
// Đề: Trả về chỉ số ký tự xuất hiện đúng một lần đầu tiên, -1 nếu không có.
// Ràng buộc: Chuỗi ASCII.
// Ý tưởng: Đếm tần suất mọi ký tự, rồi duyệt lại tìm ký tự có tần suất 1.
// Độ phức tạp: Time O(n) / Space O(1) (bảng 256 phần tử).
// Thực tế: Xử lý chuỗi, lọc phần tử duy nhất.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int firstUniqChar(const string& s){
    int cnt[256] = {0};
    for (unsigned char c : s)
        cnt[c]++;
    for (int i = 0; i < (int)s.size(); i++){
        if (cnt[(unsigned char)s[i]] == 1)
            return i;
    }
    return -1;
}

int main(){
    // Test case
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("aabb") == -1);

    cout << "OK\n";
}
