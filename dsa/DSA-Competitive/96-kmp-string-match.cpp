// 96 - KMP String Matching | Tìm mẫu trong chuỗi (Knuth-Morris-Pratt)
// Đề: Chỉ số xuất hiện đầu tiên của pattern trong text, -1 nếu không có.
// Ràng buộc: 0 <= |pattern| <= |text| <= 1e6.
// Ý tưởng: Mảng prefix-function (lps) giúp không so lại từ đầu khi lệch.
// Độ phức tạp: Time O(n + m) / Space O(m).
// Thực tế: Tìm kiếm chuỗi tuyến tính (grep, phân tích log).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int strStr(const string& text, const string& pat){
    if (pat.empty())
        return 0;
    int m = pat.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ){
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    for (int i = 0, j = 0; i < (int)text.size(); ){
        if (text[i] == pat[j]){
            i++;
            j++;
            if (j == m)
                return i - m;
        } else if (j){
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return -1;
}

int main(){
    // Test case
    assert(strStr("hello", "ll") == 2);
    assert(strStr("aaaaa", "bba") == -1);
    assert(strStr("abc", "") == 0);
    assert(strStr("mississippi", "issip") == 4);

    cout << "OK\n";
}
