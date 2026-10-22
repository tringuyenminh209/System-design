# 03 - Min Element | Phần tử nhỏ nhất
# Đề: Trả về phần tử nhỏ nhất của mảng.
# Ràng buộc: Mảng không rỗng (n >= 1).
# Ý tưởng: Giữ biến min, duyệt một lần và cập nhật.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Tìm giá trị thấp nhất (giá rẻ nhất, nhiệt độ thấp nhất).


def min_element(a):
    m = a[0]
    for x in a:
        if x < m:
            m = x
    return m


if __name__ == "__main__":
    # Test case
    assert min_element([3, 7, 2, 9, 4]) == 2
    assert min_element([-5, -2, -9]) == -9
    assert min_element([42]) == 42

    print("OK")
