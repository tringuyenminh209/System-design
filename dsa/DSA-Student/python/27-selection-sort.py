# 27 - Selection Sort | Sắp xếp chọn
# Đề: Sắp xếp mảng tăng dần.
# Ràng buộc: Chỉ dùng để học.
# Ý tưởng: Mỗi lượt chọn phần tử nhỏ nhất còn lại đưa lên đầu đoạn chưa sắp.
# Độ phức tạp: Time O(n^2) / Space O(1).
# Thực tế: Ít phép đổi chỗ hơn bubble sort.


def selection_sort(a):
    a = a[:]
    for i in range(len(a)):
        min_idx = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]
    return a


if __name__ == "__main__":
    # Test case
    assert selection_sort([64, 25, 12, 22, 11]) == [11, 12, 22, 25, 64]

    print("OK")
