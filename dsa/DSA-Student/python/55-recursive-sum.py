# 55 - Recursive Sum | Tổng 1..n bằng đệ quy
# Đề: Tính sum(n) = n + sum(n-1), với sum(0) = 0.
# Ràng buộc: n >= 0 (đủ nhỏ để không vượt giới hạn đệ quy).
# Ý tưởng: Minh họa đệ quy có điều kiện dừng (base case).
# Độ phức tạp: Time O(n) / Space O(n) (ngăn xếp đệ quy).
# Thực tế: Hiểu base case, tránh đệ quy vô hạn.


def recursive_sum(n):
    if n <= 0:
        return 0
    return n + recursive_sum(n - 1)


if __name__ == "__main__":
    # Test case
    assert recursive_sum(5) == 15
    assert recursive_sum(0) == 0
    assert recursive_sum(100) == 5050

    print("OK")
