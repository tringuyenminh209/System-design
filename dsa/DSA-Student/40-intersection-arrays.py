# 40 - Intersection of Arrays | Giao hai mảng (giá trị duy nhất)
# Đề: Trả về các giá trị có ở cả hai mảng, mỗi giá trị một lần, đã sắp.
# Ràng buộc: 0 <= n, m <= 1e5.
# Ý tưởng: Giao hai set rồi sắp xếp.
# Độ phức tạp: Time O(n + m) / Space O(n).
# Thực tế: So khớp hai tập dữ liệu.


def intersection(a, b):
    return sorted(set(a) & set(b))


if __name__ == "__main__":
    # Test case
    assert intersection([1, 2, 2, 1], [2, 2]) == [2]
    assert intersection([4, 9, 5], [9, 4, 9, 8, 4]) == [4, 9]

    print("OK")
