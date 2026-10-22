// 53 - Reverse Words | Đảo thứ tự các từ
// Đề: "the sky is blue" -> "blue is sky the".
// Ràng buộc: Các từ cách nhau bởi dấu cách.
// Ý tưởng: Tách chuỗi thành các từ rồi ghép lại theo thứ tự ngược.
// Độ phức tạp: Time O(n) / Space O(n).
// Thực tế: Xử lý câu, chuẩn hóa chuỗi.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
string reverseWords(const string& s){
    istringstream iss(s);
    vector<string> words;
    string token;
    while (iss >> token)
        words.push_back(token);
    string result;
    for (int i = (int)words.size() - 1; i >= 0; i--){
        result += words[i];
        if (i)
            result += " ";
    }
    return result;
}

int main(){
    // Test case
    assert(reverseWords("the sky is blue") == "blue is sky the");
    assert(reverseWords("hello") == "hello");

    cout << "OK\n";
}
