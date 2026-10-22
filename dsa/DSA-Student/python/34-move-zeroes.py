# 34 - Move Zeroes | Dồn số 0 về cuối
# Đề: Chuyển mọi số 0 về cuối, giữ nguyên thứ tự các số khác.
# Ràng buộc: 0 <= n <= 1e5.
# Ý tưởng: Con trỏ ghi j - dồn các số khác 0 lên trước, phần còn lại điền 0.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Nén dữ liệu, loại bỏ giá trị rỗng tại chỗ.


def move_zeroes(a):
    a = a[:]
    j = 0
    for x in a:
        if x != 0:
            a[j] = x
            j += 1
    for k in range(j, len(a)):
        a[k] = 0
    return a


if __name__ == "__main__":
    # Test case
    assert move_zeroes([0, 1, 0, 3, 12]) == [1, 3, 12, 0, 0]
    assert move_zeroes([0, 0]) == [0, 0]

    print("OK")
