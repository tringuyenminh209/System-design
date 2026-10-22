# 59 - Daily Temperatures | Số ngày chờ đến ngày ấm hơn
# Đề: Với mỗi ngày, sau bao nhiêu ngày thì nhiệt độ cao hơn (0 nếu không có).
# Ràng buộc: 1 <= n <= 1e5.
# Ý tưởng: Monotonic stack lưu chỉ số các ngày có nhiệt độ giảm dần.
# Độ phức tạp: Time O(n) / Space O(n).
# Thực tế: Mẫu next-greater dạng khoảng cách.


def daily_temperatures(t):
    res = [0] * len(t)
    st = []  # lưu chỉ số, nhiệt độ giảm dần
    for i, temp in enumerate(t):
        while st and temp > t[st[-1]]:
            j = st.pop()
            res[j] = i - j
        st.append(i)
    return res


if __name__ == "__main__":
    # Test case
    assert daily_temperatures([73, 74, 75, 71, 69, 72, 76, 73]) == [1, 1, 4, 2, 1, 1, 0, 0]

    print("OK")
