# 100 - N-Queens | Đếm số cách đặt n hậu không ăn nhau
# Đề: Số cách đặt n quân hậu trên bàn n*n sao cho không quân nào ăn nhau.
# Ràng buộc: 1 <= n <= 12 (n lớn hơn sẽ rất chậm).
# Ý tưởng: Quay lui theo từng hàng; dùng set cột và hai đường chéo đã bị chiếm.
# Độ phức tạp: Time O(n!) (có cắt tỉa) / Space O(n).
# Thực tế: Mẫu backtracking kinh điển (xếp lịch, tô màu).


def total_n_queens(n):
    count = 0
    col = set()
    d1 = set()
    d2 = set()

    def solve(row):
        nonlocal count
        if row == n:
            count += 1
            return
        for c in range(n):
            if c in col or (row + c) in d1 or (row - c) in d2:
                continue
            col.add(c)
            d1.add(row + c)
            d2.add(row - c)
            solve(row + 1)
            col.discard(c)          # hoàn tác (backtrack)
            d1.discard(row + c)
            d2.discard(row - c)

    solve(0)
    return count


if __name__ == "__main__":
    # Test case
    assert total_n_queens(1) == 1
    assert total_n_queens(4) == 2
    assert total_n_queens(8) == 92

    print("OK")
