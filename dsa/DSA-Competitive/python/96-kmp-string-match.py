# 96 - KMP String Matching | Tìm mẫu trong chuỗi (Knuth-Morris-Pratt)
# Đề: Chỉ số xuất hiện đầu tiên của pattern trong text, -1 nếu không có.
# Ràng buộc: 0 <= |pattern| <= |text| <= 1e6.
# Ý tưởng: Mảng prefix-function (lps) giúp không so lại từ đầu khi lệch.
# Độ phức tạp: Time O(n + m) / Space O(m).
# Thực tế: Tìm kiếm chuỗi tuyến tính (grep, phân tích log).


def str_str(text, pat):
    if not pat:
        return 0
    m = len(pat)
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length:
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    i = j = 0
    while i < len(text):
        if text[i] == pat[j]:
            i += 1
            j += 1
            if j == m:
                return i - m
        elif j:
            j = lps[j - 1]
        else:
            i += 1
    return -1


if __name__ == "__main__":
    # Test case
    assert str_str("hello", "ll") == 2
    assert str_str("aaaaa", "bba") == -1
    assert str_str("abc", "") == 0
    assert str_str("mississippi", "issip") == 4

    print("OK")
