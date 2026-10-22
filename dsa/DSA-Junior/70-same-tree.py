# 70 - Same Tree | Hai cây có giống nhau không
# Đề: Hai cây giống hệt về cấu trúc và giá trị?
# Ràng buộc: Cây có thể rỗng.
# Ý tưởng: Đệ quy so song song gốc và hai cây con tương ứng.
# Độ phức tạp: Time O(n) / Space O(h).
# Thực tế: So sánh cấu trúc dữ liệu cây.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def same_tree(a, b):
    if not a and not b:
        return True
    if not a or not b or a.val != b.val:
        return False
    return same_tree(a.l, b.l) and same_tree(a.r, b.r)


if __name__ == "__main__":
    # Test case
    a = T(1)
    a.l = T(2)
    b = T(1)
    b.l = T(2)
    assert same_tree(a, b)
    c = T(1)
    c.r = T(2)
    assert not same_tree(a, c)

    print("OK")
