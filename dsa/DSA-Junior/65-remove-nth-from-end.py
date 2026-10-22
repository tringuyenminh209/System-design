# 65 - Remove Nth From End | Xóa nút thứ n từ cuối
# Đề: Xóa nút thứ n tính từ cuối (n >= 1) và trả về đầu danh sách.
# Ràng buộc: 1 <= n <= độ dài danh sách.
# Ý tưởng: Hai con trỏ cách nhau n bước, dùng dummy để xử lý xóa nút đầu.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Khoảng cách cố định giữa hai con trỏ.


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


def remove_nth(head, n):
    dummy = Node(0)
    dummy.next = head
    fast = slow = dummy
    for _ in range(n):
        fast = fast.next
    while fast.next:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next


if __name__ == "__main__":
    # Test case
    assert to_list(remove_nth(build([1, 2, 3, 4, 5]), 2)) == [1, 2, 3, 5]
    assert to_list(remove_nth(build([1]), 1)) == []

    print("OK")
