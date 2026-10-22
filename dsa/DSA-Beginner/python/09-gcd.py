# 09 - GCD | Ước chung lớn nhất (thuật toán Euclid)
# Đề: Tìm ước chung lớn nhất của a và b.
# Ràng buộc: a, b >= 0.
# Ý tưởng: gcd(a, b) = gcd(b, a % b), lặp tới khi b = 0.
# Độ phức tạp: Time O(log(min(a,b))) / Space O(1).
# Thực tế: Rút gọn phân số, đồng bộ chu kỳ.


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    # Test case
    assert gcd(12, 18) == 6
    assert gcd(5, 0) == 5
    assert gcd(7, 13) == 1

    print("OK")
