# 08 - Is Prime | Kiểm tra số nguyên tố
# Đề: Kiểm tra n có phải số nguyên tố không.
# Ràng buộc: n là số nguyên bất kỳ.
# Ý tưởng: Thử các ước từ 2 tới sqrt(n); có ước thì không nguyên tố.
# Độ phức tạp: Time O(sqrt(n)) / Space O(1).
# Thực tế: Cơ sở nhiều bài số học; mẹo dừng ở căn bậc hai.


def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


if __name__ == "__main__":
    # Test case
    assert not is_prime(1)
    assert is_prime(2)
    assert is_prime(17)
    assert not is_prime(18)

    print("OK")
