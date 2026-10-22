# 56 - Longest Substring Without Repeating | Chuỗi con dài nhất không lặp ký tự
# Đề: Tìm độ dài chuỗi con dài nhất mà mọi ký tự khác nhau.
# Ràng buộc: Chuỗi bất kỳ.
# Ý tưởng: Sliding window - lưu vị trí gần nhất của mỗi ký tự để dời đầu cửa sổ.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Kỹ thuật cửa sổ trượt, xử lý luồng dữ liệu.


def length_of_longest_substring(s):
    last = {}
    start = best = 0
    for i, c in enumerate(s):
        if c in last and last[c] >= start:
            start = last[c] + 1
        last[c] = i
        best = max(best, i - start + 1)
    return best


if __name__ == "__main__":
    # Test case
    assert length_of_longest_substring("abcabcbb") == 3
    assert length_of_longest_substring("bbbbb") == 1
    assert length_of_longest_substring("") == 0
    assert length_of_longest_substring("pwwkew") == 3

    print("OK")
