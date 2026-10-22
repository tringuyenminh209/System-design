# 12 - Count Digits | Đếm số chữ số
# Đề: Đếm số chữ số của |n| (quy ước 0 có 1 chữ số).
# Ràng buộc: n là số nguyên bất kỳ.
# Ý tưởng: Chia cho 10 tới khi hết, mỗi lần tăng bộ đếm.
# Độ phức tạp: Time O(log n) / Space O(1).
# Thực tế: Định dạng hiển thị, căn lề số.


def count_digits(n):
    n = abs(n)
    count = 0
    while True:
        count += 1
        n //= 10
        if n == 0:
            break
    return count


if __name__ == "__main__":
    # Test case
    assert count_digits(123) == 3
    assert count_digits(0) == 1
    assert count_digits(-4567) == 4

    print("OK")
