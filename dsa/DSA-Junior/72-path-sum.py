# 72 - Path Sum | Có đường gốc-tới-lá tổng bằng target?
# Đề: Tồn tại đường từ gốc tới lá có tổng giá trị = target?
# Ràng buộc: Cây có thể rỗng (trả về False).
# Ý tưởng: Đệ quy trừ dần target; tại lá kiểm tra phần còn lại.
# Độ phức tạp: Time O(n) / Space O(h).
# Thực tế: Duyệt cây kèm trạng thái tích lũy.


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def has_path_sum(n, target):
    if not n:
        return False
    if not n.l and not n.r:
        return target == n.val
    return has_path_sum(n.l, target - n.val) or has_path_sum(n.r, target - n.val)


if __name__ == "__main__":
    # Test case
    r = T(5)
    r.l = T(4)
    r.r = T(8)
    r.l.l = T(11)
    r.l.l.l = T(7)
    r.l.l.r = T(2)
    assert has_path_sum(r, 22)
    assert not has_path_sum(r, 100)

    print("OK")
