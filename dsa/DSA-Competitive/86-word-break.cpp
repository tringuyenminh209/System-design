// 86 - Word Break | Tách chuỗi thành các từ trong từ điển
// Đề: s có thể tách thành dãy từ (được lặp) thuộc từ điển không.
// Ràng buộc: 1 <= |s| <= 300.
// Ý tưởng: DP - dp[i] = true nếu s[0..i) tách được; thử mọi điểm cắt j < i.
// Độ phức tạp: Time O(n^2 * L) / Space O(n).
// Thực tế: Tách token, kiểm tra hợp lệ chuỗi (bàn phím tiếng Nhật/Trung).

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
bool wordBreak(const string& s, const vector<string>& dict){
    unordered_set<string> words(dict.begin(), dict.end());
    int n = s.size();
    vector<char> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if (dp[j] && words.count(s.substr(j, i - j))){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}

int main(){
    // Test case
    assert(wordBreak("leetcode", {"leet", "code"}));
    assert(wordBreak("applepenapple", {"apple", "pen"}));
    assert(!wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}));

    cout << "OK\n";
}
