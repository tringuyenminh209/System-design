// 14 - Palindrome Number | Số đối xứng
// Đề: Kiểm tra n có đọc xuôi ngược giống nhau không.
// Ràng buộc: Số âm luôn không đối xứng (trả về false).
// Ý tưởng: Đảo ngược số rồi so sánh với số gốc.
// Độ phức tạp: Time O(log n) / Space O(1).
// Thực tế: Kiểm tra tính đối xứng của dữ liệu.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool isPalindrome(long long n){
    if (n < 0)
        return false;
    long long t = n, reversed = 0;
    while (t){
        reversed = reversed * 10 + t % 10;
        t /= 10;
    }
    return reversed == n;
}

int main(){
    // Test case
    assert(isPalindrome(121));
    assert(!isPalindrome(123));
    assert(!isPalindrome(-121));
    assert(isPalindrome(0));

    cout << "OK\n";
}
