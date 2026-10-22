# 67 - Max Depth of Binary Tree | Chiều sâu lớn nhất
# Đề: Số nút trên đường dài nhất từ gốc tới lá.
# Ràng buộc: Cây có thể rỗng (độ sâu 0).
# Ý tưởng: Đệ quy - độ sâu = 1 + max(độ sâu trái, độ sâu phải).
# Độ phức tạp: Time O(n) / Space O(h).
# Thực tế: Đo độ cao cây, nền tảng nhiều bài về cây.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def max_depth(n):
    if not n:
        return 0
    return 1 + max(max_depth(n.l), max_depth(n.r))


if __name__ == "__main__":
    # Test case
    root = T(3)
    root.l = T(9)
    root.r = T(20)
    root.r.l = T(15)
    root.r.r = T(7)
    assert max_depth(root) == 3
    assert max_depth(None) == 0

    print("OK")
