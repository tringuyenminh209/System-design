# 90 - Union-Find (DSU) | Cấu trúc hợp-tìm
# Đề: Đếm số thành phần liên thông sau các phép hợp.
# Ràng buộc: Số phần tử n cho trước.
# Ý tưởng: Cây đại diện với nén đường và hợp theo hạng.
# Độ phức tạp: Gần O(1) khấu hao mỗi thao tác.
# Thực tế: Nhóm phần tử, thuật toán Kruskal, kết nối mạng.


class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.comp = n

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]  # nén đường
            x = self.parent[x]
        return x

    def unite(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.parent[b] = a
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1
        self.comp -= 1


if __name__ == "__main__":
    # Test case
    d = DSU(5)
    d.unite(0, 1)
    d.unite(1, 2)
    d.unite(3, 4)
    assert d.comp == 2
    assert d.find(0) == d.find(2)
    assert d.find(0) != d.find(3)

    print("OK")
