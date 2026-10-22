// 38 - Reverse Vowels | Đảo vị trí các nguyên âm
// Đề: Chỉ đảo chỗ các nguyên âm, giữ nguyên phụ âm. Ví dụ hello -> holle.
// Ràng buộc: Nguyên âm không phân biệt hoa thường.
// Ý tưởng: Two pointers, chỉ đổi chỗ khi cả hai đầu đều là nguyên âm.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Two pointers có điều kiện lọc.

#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: kiểm tra nguyên âm
bool isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Hàm giải quyết bài toán
string reverseVowels(string s){
    int l = 0, r = (int)s.size() - 1;
    while (l < r){
        if (!isVowel(s[l])) l++;
        else if (!isVowel(s[r])) r--;
        else {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    return s;
}

int main(){
    // Test case
    assert(reverseVowels("hello") == "holle");
    assert(reverseVowels("leetcode") == "leotcede");

    cout << "OK\n";
}
