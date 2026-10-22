# 26 - Bubble Sort | Sắp xếp nổi bọt
# Đề: Sắp xếp mảng tăng dần.
# Ràng buộc: Chỉ dùng để học (chậm với n lớn).
# Ý tưởng: Đổi chỗ cặp kề sai thứ tự; dừng sớm nếu một lượt không đổi chỗ.
# Độ phức tạp: Time O(n^2) / Space O(1).
# Thực tế: Dễ hiểu nhưng ít dùng thực chiến.


def bubble_sort(a):
    a = a[:]
    n = len(a)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        if not swapped:
            break
    return a


if __name__ == "__main__":
    # Test case
    assert bubble_sort([5, 2, 4, 1, 3]) == [1, 2, 3, 4, 5]
    assert bubble_sort([]) == []

    print("OK")
