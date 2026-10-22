# 60 - Next Greater Element | Phần tử lớn hơn kế tiếp bên phải
# Đề: Với mỗi phần tử, tìm giá trị lớn hơn đầu tiên ở bên phải (-1 nếu không có).
# Ràng buộc: 1 <= n <= 1e5.
# Ý tưởng: Monotonic stack lưu chỉ số các phần tử chưa tìm được "lớn hơn".
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Mẫu next-greater kinh điển (giá cổ phiếu, nhiệt độ).


def next_greater(a):
    res = [-1] * len(a)
    st = []
    for i, x in enumerate(a):
        while st and x > a[st[-1]]:
            res[st.pop()] = x
        st.append(i)
    return res


if __name__ == "__main__":
    # Test case
    assert next_greater([2, 1, 2, 4, 3]) == [4, 2, 4, -1, -1]

    print("OK")
