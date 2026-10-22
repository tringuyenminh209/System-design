// 98 - Longest Palindromic Substring | Chuỗi con đối xứng dài nhất
// Đề: Trả về một chuỗi con đối xứng dài nhất.
// Ràng buộc: 1 <= |s| <= 1000.
// Ý tưởng: Nở từ tâm - với 2n-1 tâm (đơn và đôi), mở rộng khi hai bên còn khớp.
// Độ phức tạp: Time O(n^2) / Space O(1).
// Thực tế: Xử lý chuỗi; kỹ thuật expand-around-center dễ hiểu, đủ nhanh.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
string longestPalindrome(const string& s){
    if (s.empty())
        return "";
    int start = 0, len = 1;
    auto expand = [&](int l, int r){
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        if (r - l - 1 > len){
            len = r - l - 1;
            start = l + 1;
        }
    };
    for (int i = 0; i < (int)s.size(); i++){
        expand(i, i);       // tâm đơn
        expand(i, i + 1);   // tâm đôi
    }
    return s.substr(start, len);
}

int main(){
    // Test case
    string r = longestPalindrome("babad");
    assert(r == "bab" || r == "aba");
    assert(longestPalindrome("cbbd") == "bb");
    assert(longestPalindrome("a") == "a");

    cout << "OK\n";
}
