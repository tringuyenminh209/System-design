# 41 - Single Number | Số xuất hiện một lần
# Đề: Mọi phần tử xuất hiện 2 lần trừ đúng 1 phần tử; tìm phần tử đó.
# Ràng buộc: Đúng một phần tử lẻ, còn lại theo cặp.
# Ý tưởng: XOR toàn mảng - các cặp giống nhau triệt tiêu về 0.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Mẹo XOR kinh điển, tiết kiệm bộ nhớ.


def single_number(a):
    x = 0
    for v in a:
        x ^= v
    return x


if __name__ == "__main__":
    # Test case
    assert single_number([2, 2, 1]) == 1
    assert single_number([4, 1, 2, 1, 2]) == 4

    print("OK")
