// 56 - Longest Substring Without Repeating | Chuỗi con dài nhất không lặp ký tự
// Đề: Tìm độ dài chuỗi con dài nhất mà mọi ký tự khác nhau.
// Ràng buộc: Chuỗi ASCII.
// Ý tưởng: Sliding window - lưu vị trí gần nhất của mỗi ký tự để dời đầu cửa sổ.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Kỹ thuật cửa sổ trượt, xử lý luồng dữ liệu.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int lengthOfLongestSubstring(const string& s){
    int last[256];
    fill(last, last + 256, -1);
    int best = 0, start = 0;
    for (int i = 0; i < (int)s.size(); i++){
        unsigned char c = s[i];
        if (last[c] >= start)
            start = last[c] + 1;
        last[c] = i;
        best = max(best, i - start + 1);
    }
    return best;
}

int main(){
    // Test case
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring("pwwkew") == 3);

    cout << "OK\n";
}
