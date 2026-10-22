# 29 - Binary Search | Tìm kiếm nhị phân
# Đề: Trên mảng đã sắp tăng, trả về chỉ số target, -1 nếu không có.
# Ràng buộc: Mảng phải được sắp xếp trước.
# Ý tưởng: Chia đôi khoảng tìm kiếm dựa vào so sánh với phần tử giữa.
# Độ phức tạp: Time O(log n) / Space O(1).
# Thực tế: Nền tảng tra cứu nhanh trên dữ liệu đã sắp.


def binary_search(a, target):
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == target:
            return mid
        if a[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


if __name__ == "__main__":
    # Test case
    assert binary_search([1, 3, 5, 7, 9], 7) == 3
    assert binary_search([1, 3, 5, 7, 9], 4) == -1
    assert binary_search([], 1) == -1

    print("OK")
