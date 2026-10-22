# 32 - Contains Duplicate | Có phần tử trùng không?
# Đề: Trả về True nếu tồn tại giá trị xuất hiện >= 2 lần.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: So sánh kích thước set với list; khác nhau tức có trùng.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Kiểm tra tính duy nhất (email, mã) trước khi lưu.


def contains_duplicate(a):
    return len(set(a)) != len(a)


if __name__ == "__main__":
    # Test case
    assert contains_duplicate([1, 2, 3, 1])
    assert not contains_duplicate([1, 2, 3, 4])
    assert not contains_duplicate([])

    print("OK")
