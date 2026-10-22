# 20 - Count Positive/Negative | Đếm số dương và âm
# Ngôn ngữ: Python
# Đề: Trả về cặp (số dương, số âm); số 0 không tính.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Duyệt mảng, so sánh mỗi phần tử với 0.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Phân tích lãi/lỗ, tăng/giảm.


def count_pos_neg(a):
    pos = 0
    neg = 0
    for x in a:
        if x > 0:
            pos += 1  # số dương
        elif x < 0:
            neg += 1  # số âm; x == 0 rơi qua cả 2 nhánh -> bỏ qua
    return (pos, neg)  # tuple: trả về cặp (dương, âm) trong một lần return


if __name__ == "__main__":
    # Test case
    assert count_pos_neg([-1, 0, 2, 3, -4]) == (2, 2)
    assert count_pos_neg([0, 0]) == (0, 0)

    print("OK")
