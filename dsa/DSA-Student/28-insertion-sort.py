# 28 - Insertion Sort | Sắp xếp chèn
# Đề: Sắp xếp mảng tăng dần.
# Ràng buộc: Hiệu quả với dữ liệu nhỏ hoặc gần như đã sắp.
# Ý tưởng: Chèn từng phần tử vào đúng vị trí trong phần đã sắp phía trước.
# Độ phức tạp: Time O(n^2), tốt nhất O(n) / Space O(1).
# Thực tế: Nhanh cho mảng nhỏ; dùng trong các thư viện sort lai.


def insertion_sort(a):
    a = a[:]
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    return a


if __name__ == "__main__":
    # Test case
    assert insertion_sort([5, 2, 4, 6, 1, 3]) == [1, 2, 3, 4, 5, 6]

    print("OK")
