# 19 - Second Largest | Phần tử lớn nhì (phân biệt giá trị)
# Ngôn ngữ: Python
# Đề: Trả về giá trị lớn thứ hai, -1 nếu không tồn tại.
# Ràng buộc: Giá trị lớn nhì phải KHÁC giá trị lớn nhất.
# Ý tưởng: Giữ hai biến best1, best2 và cập nhật khi gặp giá trị mới.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Xếp hạng, tìm á quân.


def second_largest(a):
    # float("-inf"): âm vô cực, làm mốc "chưa có" (nhỏ hơn mọi số thật)
    best1 = best2 = float("-inf")  # best1 = lớn nhất, best2 = lớn nhì
    for x in a:
        if x > best1:  # x vượt lớn nhất -> best1 cũ tụt xuống làm best2
            best2, best1 = best1, x
        elif best2 < x < best1:  # x < best1 để loại giá trị TRÙNG lớn nhất
            best2 = x
    return -1 if best2 == float("-inf") else best2  # vẫn là mốc -> không tồn tại


if __name__ == "__main__":
    # Test case
    assert second_largest([3, 1, 4, 1, 5]) == 4
    assert second_largest([5, 5, 4]) == 4
    assert second_largest([7, 7, 7]) == -1

    print("OK")
