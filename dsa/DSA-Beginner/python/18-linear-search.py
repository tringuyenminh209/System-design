# 18 - Linear Search | Tìm kiếm tuyến tính
# Ngôn ngữ: Python
# Đề: Trả về chỉ số đầu tiên của target, -1 nếu không tồn tại.
# Ràng buộc: Mảng chưa cần sắp xếp.
# Ý tưởng: Duyệt tuần tự và so sánh từng phần tử.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Dùng khi dữ liệu nhỏ hoặc chưa được sắp xếp.


def search(a, target):
    for i, x in enumerate(a):  # enumerate: cho cả chỉ số i lẫn giá trị x trong một vòng lặp
        if x == target:
            return i  # gặp là trả về ngay -> luôn ra chỉ số ĐẦU TIÊN
    return -1  # duyệt hết không thấy


if __name__ == "__main__":
    # Test case
    assert search([4, 2, 7, 1], 7) == 2
    assert search([4, 2, 7, 1], 9) == -1
    assert search([], 1) == -1

    print("OK")
