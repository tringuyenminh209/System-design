// 54 - Palindrome String | Chuỗi đối xứng
// Đề: Kiểm tra chuỗi đọc xuôi ngược có giống nhau không.
// Ràng buộc: So sánh chính xác từng ký tự.
// Ý tưởng: Two pointers so ký tự đầu và cuối, tiến dần vào giữa.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Kiểm tra đối xứng; biến thể: bỏ qua ký tự không phải chữ-số.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool isPalindrome(const string& s){
    int l = 0, r = (int)s.size() - 1;
    while (l < r){
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main(){
    // Test case
    assert(isPalindrome("racecar"));
    assert(!isPalindrome("hello"));
    assert(isPalindrome(""));

    cout << "OK\n";
}
