# 35 - Remove Duplicates (sorted) | Bỏ trùng trên mảng đã sắp
# Đề: Trả về mảng các giá trị duy nhất theo thứ tự.
# Ràng buộc: Mảng đầu vào đã được sắp xếp.
# Ý tưởng: So sánh với phần tử cuối của kết quả để bỏ trùng liền kề.
# Độ phức tạp: Time O(n) / Space O(1) (không kể output).
# Thực tế: Khử trùng dữ liệu đã sắp.


def remove_dup(a):
    result = []
    for x in a:
        if not result or result[-1] != x:
            result.append(x)
    return result


if __name__ == "__main__":
    # Test case
    assert remove_dup([1, 1, 2, 3, 3]) == [1, 2, 3]
    assert remove_dup([]) == []

    print("OK")
