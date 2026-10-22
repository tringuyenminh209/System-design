# 71 - Symmetric Tree | Cây đối xứng qua trục giữa
# Đề: Cây có đối xứng gương không?
# Ràng buộc: Cây có thể rỗng (coi là đối xứng).
# Ý tưởng: So hai nhánh ngược nhau: trái-phải với phải-trái.
# Độ phức tạp: Time O(n) / Space O(h).
# Thực tế: Đệ quy trên cặp nút, biến thể của same-tree.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def mirror(a, b):
    if not a and not b:
        return True
    if not a or not b or a.val != b.val:
        return False
    return mirror(a.l, b.r) and mirror(a.r, b.l)


def is_symmetric(root):
    return not root or mirror(root.l, root.r)


if __name__ == "__main__":
    # Test case
    r = T(1)
    r.l = T(2)
    r.r = T(2)
    r.l.l = T(3)
    r.r.r = T(3)
    assert is_symmetric(r)
    r.r.r.val = 4
    assert not is_symmetric(r)

    print("OK")
