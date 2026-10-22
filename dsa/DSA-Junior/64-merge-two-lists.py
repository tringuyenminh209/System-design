# 64 - Merge Two Sorted Lists | Trộn 2 danh sách liên kết đã sắp
# Đề: Gộp hai danh sách tăng dần thành một danh sách tăng dần.
# Ràng buộc: Hai danh sách đầu vào đã sắp.
# Ý tưởng: Dùng dummy head, nối dần nút nhỏ hơn ở đầu hai danh sách.
# Độ phức tạp: Time O(n + m) / Space O(1).
# Thực tế: Thao tác merge trên con trỏ; lõi của merge sort danh sách.


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


def merge_two(a, b):
    dummy = Node(0)
    t = dummy
    while a and b:
        if a.val <= b.val:
            t.next = a
            a = a.next
        else:
            t.next = b
            b = b.next
        t = t.next
    t.next = a if a else b
    return dummy.next


if __name__ == "__main__":
    # Test case
    assert to_list(merge_two(build([1, 2, 4]), build([1, 3, 4]))) == [1, 1, 2, 3, 4, 4]

    print("OK")
