# 02 - Max Element | Phần tử lớn nhất
# Đề: Trả về phần tử lớn nhất của mảng.
# Ràng buộc: Mảng không rỗng (n >= 1).
# Ý tưởng: Giữ biến max, duyệt một lần và cập nhật.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Tìm giá trị đỉnh (doanh thu cao nhất, điểm cao nhất).


def max_element(a):
    m = a[0]
    for x in a:
        if x > m:
            m = x
    return m


if __name__ == "__main__":
    # Test case
    assert max_element([3, 7, 2, 9, 4]) == 9
    assert max_element([-5, -2, -9]) == -2
    assert max_element([42]) == 42

    print("OK")
