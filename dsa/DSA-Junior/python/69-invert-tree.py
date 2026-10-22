# 69 - Invert Binary Tree | Lật gương cây nhị phân
# Đề: Đổi chỗ con trái và con phải ở mọi nút.
# Ràng buộc: Cây có thể rỗng.
# Ý tưởng: Đệ quy hoán đổi hai con rồi lật tiếp hai cây con.
# Độ phức tạp: Time O(n) / Space O(h).
# Thực tế: Bài phỏng vấn nổi tiếng; thao tác đệ quy trên cây.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def invert(n):
    if not n:
        return None
    n.l, n.r = n.r, n.l
    invert(n.l)
    invert(n.r)
    return n


def inorder(n, o):
    if not n:
        return
    inorder(n.l, o)
    o.append(n.val)
    inorder(n.r, o)


if __name__ == "__main__":
    # Test case
    root = T(4)
    root.l = T(2)
    root.r = T(7)
    invert(root)
    o = []
    inorder(root, o)
    assert o == [7, 4, 2]

    print("OK")
