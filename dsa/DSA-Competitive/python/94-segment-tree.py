# 94 - Segment Tree | Cây phân đoạn (tổng đoạn + cập nhật điểm)
# Đề: Hỗ trợ cập nhật một phần tử và truy vấn tổng đoạn [l, r].
# Ràng buộc: Nhiều truy vấn/cập nhật xen kẽ.
# Ý tưởng: Cây nhị phân, mỗi nút giữ tổng một đoạn; cài đặt lặp (iterative).
# Độ phức tạp: Time O(log n) mỗi thao tác / Space O(n).
# Thực tế: Truy vấn/cập nhật xen kẽ trên mảng động.


class SegTree:
    def __init__(self, a):
        self.n = len(a)
        self.t = [0] * (2 * self.n)
        self.t[self.n:] = a
        for i in range(self.n - 1, 0, -1):
            self.t[i] = self.t[2 * i] + self.t[2 * i + 1]

    def update(self, i, val):
        i += self.n
        self.t[i] = val
        while i > 1:
            i >>= 1
            self.t[i] = self.t[2 * i] + self.t[2 * i + 1]

    def query(self, l, r):   # tổng đoạn [l, r]
        l += self.n
        r += self.n + 1
        s = 0
        while l < r:
            if l & 1:
                s += self.t[l]
                l += 1
            if r & 1:
                r -= 1
                s += self.t[r]
            l >>= 1
            r >>= 1
        return s


if __name__ == "__main__":
    # Test case
    st = SegTree([1, 3, 5, 7, 9, 11])
    assert st.query(1, 3) == 15
    st.update(1, 10)
    assert st.query(1, 3) == 22
    assert st.query(0, 5) == 43

    print("OK")
