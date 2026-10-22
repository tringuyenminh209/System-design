# 10 - LCM | Bội chung nhỏ nhất
# Đề: Tìm bội chung nhỏ nhất của a và b.
# Ràng buộc: a, b >= 1.
# Ý tưởng: lcm = a // gcd(a, b) * b (chia trước để số nhỏ gọn).
# Độ phức tạp: Time O(log(min(a,b))) / Space O(1).
# Thực tế: Đồng bộ hai chu kỳ khác nhau.


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a // gcd(a, b) * b


if __name__ == "__main__":
    # Test case
    assert lcm(4, 6) == 12
    assert lcm(3, 5) == 15
    assert lcm(6, 6) == 6

    print("OK")
