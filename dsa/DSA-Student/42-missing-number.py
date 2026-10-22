# 42 - Missing Number | Số thiếu trong 0..n
# Đề: Mảng chứa n số phân biệt trong [0..n]; tìm số bị thiếu.
# Ràng buộc: Đúng một số trong [0..n] bị thiếu.
# Ý tưởng: Tổng kỳ vọng 0+1+..+n trừ đi tổng thực tế.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Kiểm tra dãy liên tục có bị hụt phần tử.


def missing_number(a):
    n = len(a)
    return n * (n + 1) // 2 - sum(a)


if __name__ == "__main__":
    # Test case
    assert missing_number([3, 0, 1]) == 2
    assert missing_number([0, 1]) == 2
    assert missing_number([0]) == 1

    print("OK")
