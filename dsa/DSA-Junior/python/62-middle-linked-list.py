# 62 - Middle of Linked List | Nút giữa danh sách
# Đề: Trả về nút giữa; nếu số nút chẵn thì lấy nút giữa thứ hai.
# Ràng buộc: Danh sách không rỗng.
# Ý tưởng: Con trỏ slow đi 1 bước, fast đi 2 bước.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Kỹ thuật con trỏ nhanh-chậm (fast/slow pointers).


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


def middle_node(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


if __name__ == "__main__":
    # Test case
    assert middle_node(build([1, 2, 3, 4, 5])).val == 3
    assert middle_node(build([1, 2, 3, 4, 5, 6])).val == 4

    print("OK")
