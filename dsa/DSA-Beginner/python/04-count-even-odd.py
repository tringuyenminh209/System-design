# 04 - Count Even/Odd | Đếm số chẵn và lẻ
# Đề: Trả về cặp (số chẵn, số lẻ) trong mảng.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Duyệt mảng, kiểm tra x % 2 để phân loại.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Phân loại dữ liệu theo tính chất.


def count_even_odd(a):
    even = 0
    odd = 0
    for x in a:
        if x % 2 == 0:
            even += 1
        else:
            odd += 1
    return (even, odd)


if __name__ == "__main__":
    # Test case
    assert count_even_odd([1, 2, 3, 4, 5]) == (2, 3)
    assert count_even_odd([2, 4, 6]) == (3, 0)

    print("OK")
