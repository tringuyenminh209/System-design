# 11 - Sum of Digits | Tổng các chữ số
# Đề: Tính tổng các chữ số của |n|.
# Ràng buộc: n là số nguyên bất kỳ.
# Ý tưởng: Lấy chữ số cuối bằng n % 10, rồi bỏ đi bằng n //= 10.
# Độ phức tạp: Time O(số chữ số) / Space O(1).
# Thực tế: Checksum, kiểm tra chia hết cho 9.


def sum_digits(n):
    n = abs(n)
    total = 0
    while True:
        total += n % 10
        n //= 10
        if n == 0:
            break
    return total


if __name__ == "__main__":
    # Test case
    assert sum_digits(123) == 6
    assert sum_digits(0) == 0
    assert sum_digits(-99) == 18

    print("OK")
