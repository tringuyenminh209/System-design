# 48 - Count Primes | Đếm số nguyên tố nhỏ hơn n
# Đề: Đếm số nguyên tố trong khoảng [2, n).
# Ràng buộc: 0 <= n <= 5e6.
# Ý tưởng: Sàng Eratosthenes - gạch bội của mỗi số nguyên tố.
# Độ phức tạp: Time O(n log log n) / Space O(n).
# Thực tế: Tiền xử lý nhanh cho nhiều truy vấn về nguyên tố.


def count_primes(n):
    if n < 3:
        return 0
    composite = [False] * n
    count = 0
    for i in range(2, n):
        if not composite[i]:
            count += 1
            for j in range(i * i, n, i):
                composite[j] = True
    return count


if __name__ == "__main__":
    # Test case
    assert count_primes(10) == 4
    assert count_primes(2) == 0
    assert count_primes(0) == 0

    print("OK")
