# 46 - Integer Sqrt | Căn bậc hai làm tròn xuống
# Đề: Tính floor(sqrt(x)) cho x >= 0, chỉ dùng số nguyên.
# Ràng buộc: x >= 0.
# Ý tưởng: Nhị phân trên đáp án - tìm m lớn nhất mà m*m <= x.
# Độ phức tạp: Time O(log x) / Space O(1).
# Thực tế: Binary search trên không gian giá trị (không chỉ trên mảng).


def my_sqrt(x):
    lo, hi, ans = 0, x, 0
    while lo <= hi:
        m = (lo + hi) // 2
        if m * m <= x:
            ans = m
            lo = m + 1
        else:
            hi = m - 1
    return ans


if __name__ == "__main__":
    # Test case
    assert my_sqrt(8) == 2
    assert my_sqrt(16) == 4
    assert my_sqrt(0) == 0

    print("OK")
