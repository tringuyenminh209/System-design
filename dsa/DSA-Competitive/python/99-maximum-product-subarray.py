# 99 - Maximum Product Subarray | Tích đoạn con lớn nhất
# Đề: Tìm tích lớn nhất của một đoạn con liên tiếp.
# Ràng buộc: Mảng không rỗng; có thể chứa số âm và số 0.
# Ý tưởng: Giữ CẢ max và min hiện tại (số âm đảo dấu min thành max).
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Biến thể Kadane có bẫy số âm và số 0.


def max_product(a):
    best = mx = mn = a[0]
    for x in a[1:]:
        if x < 0:
            mx, mn = mn, mx
        mx = max(x, mx * x)
        mn = min(x, mn * x)
        best = max(best, mx)
    return best


if __name__ == "__main__":
    # Test case
    assert max_product([2, 3, -2, 4]) == 6
    assert max_product([-2, 0, -1]) == 0
    assert max_product([-2, 3, -4]) == 24

    print("OK")
