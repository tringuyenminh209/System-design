# 39 - Merge Two Sorted Arrays | Trộn 2 mảng đã sắp
# Đề: Trộn hai mảng tăng dần thành một mảng tăng dần.
# Ràng buộc: Cả hai mảng đầu vào đã được sắp.
# Ý tưởng: Two pointers so đầu hai mảng, chọn nhỏ hơn đưa vào kết quả.
# Độ phức tạp: Time O(n + m) / Space O(n + m).
# Thực tế: Bước merge trong Merge Sort, gộp dữ liệu đã sắp.


def merge(a, b):
    result = []
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1
    result.extend(a[i:])
    result.extend(b[j:])
    return result


if __name__ == "__main__":
    # Test case
    assert merge([1, 3, 5], [2, 4, 6]) == [1, 2, 3, 4, 5, 6]
    assert merge([], [1, 2]) == [1, 2]

    print("OK")
