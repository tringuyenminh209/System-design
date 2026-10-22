# 79 - Merge Intervals | Gộp các khoảng chồng lấn
# Đề: Gộp mọi khoảng [l, r] chồng nhau thành các khoảng rời.
# Ràng buộc: Khoảng cho theo cặp (đầu, cuối).
# Ý tưởng: Sắp theo đầu mút, gộp nếu khoảng mới chồng lên khoảng cuối kết quả.
# Độ phức tạp: Time O(n log n) / Space O(n).
# Thực tế: Lịch làm việc, đặt phòng, gộp khoảng thời gian.


def merge_intervals(intervals):
    res = []
    for l, r in sorted(intervals):
        if res and l <= res[-1][1]:
            res[-1] = (res[-1][0], max(res[-1][1], r))
        else:
            res.append((l, r))
    return res


if __name__ == "__main__":
    # Test case
    assert merge_intervals([(1, 3), (2, 6), (8, 10), (15, 18)]) == [(1, 6), (8, 10), (15, 18)]

    print("OK")
