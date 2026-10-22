# 75 - Climbing Stairs | Số cách leo n bậc (bước 1 hoặc 2)
# Đề: Đếm số cách lên n bậc, mỗi bước đi 1 hoặc 2 bậc.
# Ràng buộc: n >= 0.
# Ý tưởng: DP - f(n) = f(n-1) + f(n-2), chính là dãy Fibonacci.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Bài DP nhập môn kinh điển; nhận ra quan hệ truy hồi.


def climb_stairs(n):
    a = b = 1
    for _ in range(n):
        a, b = b, a + b
    return a


if __name__ == "__main__":
    # Test case
    assert climb_stairs(2) == 2
    assert climb_stairs(3) == 3
    assert climb_stairs(5) == 8

    print("OK")
