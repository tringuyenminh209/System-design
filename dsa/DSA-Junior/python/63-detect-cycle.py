# 63 - Detect Cycle | Phát hiện chu trình trong danh sách liên kết
# Đề: Danh sách có vòng lặp không.
# Ràng buộc: Danh sách có thể rỗng hoặc có vòng.
# Ý tưởng: Floyd - slow đi 1, fast đi 2; nếu gặp nhau thì có vòng.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Phát hiện lặp vô hạn; "thuật toán rùa và thỏ".


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def has_cycle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            return True
    return False


if __name__ == "__main__":
    # Test case
    a, b, c = Node(1), Node(2), Node(3)
    a.next = b
    b.next = c
    assert not has_cycle(a)
    c.next = a          # tạo vòng
    assert has_cycle(a)

    print("OK")
