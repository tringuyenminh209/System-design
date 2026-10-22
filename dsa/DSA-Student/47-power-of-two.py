# 47 - Power of Two | Kiểm tra lũy thừa của 2
# Đề: Kiểm tra n có phải 2^k (k >= 0) không.
# Ràng buộc: n là số nguyên bất kỳ.
# Ý tưởng: Số dương chỉ có đúng 1 bit bật khi n & (n-1) == 0.
# Độ phức tạp: Time O(1) / Space O(1).
# Thực tế: Mẹo bit-manipulation hay dùng (căn chỉnh bộ nhớ, hash size).


def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0


if __name__ == "__main__":
    # Test case
    assert is_power_of_two(1)
    assert is_power_of_two(16)
    assert not is_power_of_two(3)
    assert not is_power_of_two(0)

    print("OK")
