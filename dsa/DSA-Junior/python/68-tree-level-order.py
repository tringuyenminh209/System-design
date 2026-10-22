# 68 - Binary Tree Level Order | Duyệt theo tầng (BFS)
# Đề: Trả về giá trị theo từng tầng từ trên xuống dưới.
# Ràng buộc: Cây có thể rỗng.
# Ý tưởng: BFS dùng queue, xử lý trọn một tầng mỗi vòng lặp.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: BFS trên cây; nền tảng duyệt theo mức.

from collections import deque


class T:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def level_order(root):
    res = []
    if not root:
        return res
    q = deque([root])
    while q:
        level = []
        for _ in range(len(q)):
            n = q.popleft()
            level.append(n.val)
            if n.l:
                q.append(n.l)
            if n.r:
                q.append(n.r)
        res.append(level)
    return res


if __name__ == "__main__":
    # Test case
    root = T(3)
    root.l = T(9)
    root.r = T(20)
    root.r.l = T(15)
    root.r.r = T(7)
    assert level_order(root) == [[3], [9, 20], [15, 7]]

    print("OK")
