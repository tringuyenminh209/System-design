# 07 - Fibonacci thứ n | Số Fibonacci thứ n
# Đề: F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2). Tính F(n).
# Ràng buộc: n >= 0.
# Ý tưởng: Lặp giữ 2 biến gần nhất, tránh đệ quy O(2^n).
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Ví dụ kinh điển dùng lặp thay đệ quy để tối ưu.


def fib(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


if __name__ == "__main__":
    # Test case
    assert fib(0) == 0
    assert fib(1) == 1
    assert fib(10) == 55

    print("OK")
