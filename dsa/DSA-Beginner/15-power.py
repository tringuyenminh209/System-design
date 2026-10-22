# 15 - Power | Lũy thừa nhanh a^b (b >= 0)
# Đề: Tính a mũ b.
# Ràng buộc: b >= 0.
# Ý tưởng: Bình phương liên tiếp (fast exponentiation) theo bit của b.
# Độ phức tạp: Time O(log b) / Space O(1).
# Thực tế: Nhanh hơn nhân b lần; nền tảng của số học modulo.


def power(a, b):
    result = 1
    while b:
        if b & 1:
            result *= a
        a *= a
        b >>= 1
    return result


if __name__ == "__main__":
    # Test case
    assert power(2, 10) == 1024
    assert power(5, 0) == 1
    assert power(3, 3) == 27

    print("OK")
