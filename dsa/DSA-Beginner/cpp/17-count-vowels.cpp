// 17 - Count Vowels | Đếm nguyên âm
// Ngôn ngữ: C++
// Đề: Đếm số nguyên âm a, e, i, o, u trong chuỗi.
// Ràng buộc: Không phân biệt hoa thường.
// Ý tưởng: Duyệt từng ký tự, hạ về chữ thường rồi kiểm tra thuộc tập nguyên âm.
// Độ phức tạp: Time O(n) / Space O(1).
// Thực tế: Xử lý văn bản, thống kê ký tự.

#include <bits/stdc++.h>
using namespace std;

// Hàm giải quyết bài toán
int countVowels(const string& s){
    int count = 0;
    for (char ch : s){                  // duyệt từng ký tự của chuỗi
        char l = tolower(ch);           // tolower: đưa về chữ thường -> 'A' và 'a' tính như nhau
        if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
            count++;                    // là nguyên âm -> tăng biến đếm
    }
    return count;
}

int main(){
    // Test case
    assert(countVowels("hello") == 2);
    assert(countVowels("XYZ") == 0);
    assert(countVowels("AeIoU") == 5);

    cout << "OK\n";
}
