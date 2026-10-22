# 43 - Maximum Subarray | Tổng đoạn con lớn nhất (Kadane)
# Đề: Tìm tổng lớn nhất của một đoạn con liên tiếp không rỗng.
# Ràng buộc: Mảng không rỗng; có thể chứa số âm.
# Ý tưởng: Kadane - cur = max(x, cur + x); best = max(best, cur).
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Chuỗi lãi/lỗ tốt nhất, đoạn tín hiệu mạnh nhất.


def max_subarray(a):
    best = cur = a[0]
    for x in a[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best


if __name__ == "__main__":
    # Test case
    assert max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
    assert max_subarray([-1, -2, -3]) == -1

    print("OK")
