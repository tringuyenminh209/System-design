# 66 - Binary Tree Inorder | Duyệt cây nhị phân theo thứ tự giữa
# Đề: Trả về danh sách giá trị theo thứ tự trái - gốc - phải.
# Ràng buộc: Cây có thể rỗng.
# Ý tưởng: Đệ quy duyệt trái, thăm gốc, rồi duyệt phải.
# Độ phức tạp: Time O(n) / Space O(h) (chiều cao cây).
# Thực tế: Với cây tìm kiếm nhị phân, inorder cho dãy tăng dần.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def inorder(n, out):
    if not n:
        return
    inorder(n.l, out)
    out.append(n.val)
    inorder(n.r, out)


if __name__ == "__main__":
    # Test case
    root = T(1)
    root.r = T(2)
    root.r.l = T(3)
    out = []
    inorder(root, out)
    assert out == [1, 3, 2]

    print("OK")
