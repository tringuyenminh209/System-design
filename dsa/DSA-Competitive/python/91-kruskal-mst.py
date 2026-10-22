# 91 - Kruskal MST | Cây khung nhỏ nhất
# Đề: Tổng trọng số cây khung nhỏ nhất của đồ thị vô hướng liên thông.
# Ràng buộc: Đồ thị liên thông, trọng số bất kỳ.
# Ý tưởng: Sắp cạnh tăng dần, thêm cạnh nếu không tạo chu trình (dùng DSU).
# Độ phức tạp: Time O(E log E) / Space O(V).
# Thực tế: Nối mạng/đường ống với chi phí thấp nhất.


def kruskal(n, edges):
    parent = list(range(n))

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    total = 0
    for w, u, v in sorted(edges):
        ru, rv = find(u), find(v)
        if ru != rv:
            parent[ru] = rv
            total += w
    return total


if __name__ == "__main__":
    # Test case
    assert kruskal(4, [(1, 0, 1), (4, 0, 2), (2, 1, 2), (6, 1, 3), (3, 2, 3)]) == 6

    print("OK")
