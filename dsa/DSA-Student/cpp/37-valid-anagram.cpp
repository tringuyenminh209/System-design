// 37 - Valid Anagram | Hai chuỗi có phải đảo chữ của nhau
// Đề: Kiểm tra s và t có cùng đa tập ký tự không.
// Ràng buộc: Chuỗi ASCII.
// Ý tưởng: Đếm tần suất từ s rồi trừ dần theo t; âm là lệch.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Nhóm từ, kiểm tra hoán vị ký tự.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool isAnagram(const string& s, const string& t){
    if (s.size() != t.size())
        return false;
    int cnt[256] = {0};
    for (unsigned char ch : s)
        cnt[ch]++;
    for (unsigned char ch : t){
        if (--cnt[ch] < 0)
            return false;
    }
    return true;
}

int main(){
    // Test case
    assert(isAnagram("anagram", "nagaram"));
    assert(!isAnagram("rat", "car"));
    assert(isAnagram("", ""));

    cout << "OK\n";
}
