# 61 - Reverse Linked List | Đảo ngược danh sách liên kết
# Đề: Đảo chiều các con trỏ next của danh sách.
# Ràng buộc: Danh sách có thể rỗng.
# Ý tưởng: Ba con trỏ prev/cur/next, đảo chiều dần từng nút.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Thao tác con trỏ nền tảng; hay hỏi khi phỏng vấn.


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def build(vals):
    dummy = Node(0)
    t = dummy
    for x in vals:
        t.next = Node(x)
        t = t.next
    return dummy.next


def to_list(h):
    r = []
    while h:
        r.append(h.val)
        h = h.next
    return r


def reverse_list(head):
    prev = None
    while head:
        head.next, prev, head = prev, head, head.next
    return prev


if __name__ == "__main__":
    # Test case
    assert to_list(reverse_list(build([1, 2, 3, 4, 5]))) == [5, 4, 3, 2, 1]
    assert reverse_list(None) is None

    print("OK")
