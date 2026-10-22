# 95 - Fenwick Tree (BIT) | Cây chỉ số nhị phân (tổng tiền tố + cập nhật)
# Đề: Hỗ trợ cộng dồn một phần tử và truy vấn tổng tiền tố.
# Ràng buộc: Nhiều truy vấn/cập nhật xen kẽ.
# Ý tưởng: Dùng bit thấp nhất (i & -i) để nhảy qua các đoạn quản lý.
# Độ phức tạp: Time O(log n) mỗi thao tác / Space O(n).
# Thực tế: Gọn hơn segment tree cho tổng tiền tố; đếm nghịch thế.


class BIT:
    def __init__(self, n):
        self.n = n
        self.t = [0] * (n + 1)

    def add(self, i, v):
        i += 1
        while i <= self.n:
            self.t[i] += v
            i += i & -i

    def prefix(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.t[i]
            i -= i & -i
        return s

    def range(self, l, r):
        return self.prefix(r) - (self.prefix(l - 1) if l else 0)


if __name__ == "__main__":
    # Test case
    a = [1, 3, 5, 7, 9, 11]
    b = BIT(6)
    for i, x in enumerate(a):
        b.add(i, x)
    assert b.range(1, 3) == 15
    b.add(1, 7)
    assert b.range(1, 3) == 22
    assert b.prefix(5) == 43

    print("OK")
