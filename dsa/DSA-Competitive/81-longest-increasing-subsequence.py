# 81 - Longest Increasing Subsequence | Dãy con tăng dài nhất
# Đề: Tìm độ dài dãy con (không cần liên tiếp) tăng ngặt dài nhất.
# Ràng buộc: 1 <= n <= 1e5.
# Ý tưởng: Patience sorting - giữ mảng "đuôi nhỏ nhất", dùng bisect để thay/nối.
# Độ phức tạp: Time O(n log n) / Space O(n).
# Thực tế: Mẫu LIS kinh điển (phân tích xu hướng, xếp chồng hộp).

import bisect


def length_of_lis(a):
    tails = []
    for x in a:
        i = bisect.bisect_left(tails, x)
        if i == len(tails):
            tails.append(x)
        else:
            tails[i] = x
    return len(tails)


if __name__ == "__main__":
    # Test case
    assert length_of_lis([10, 9, 2, 5, 3, 7, 101, 18]) == 4
    assert length_of_lis([0, 1, 0, 3, 2, 3]) == 4
    assert length_of_lis([7, 7, 7]) == 1

    print("OK")
