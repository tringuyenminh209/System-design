# 80 - Minimum Meeting Rooms | Số phòng họp tối thiểu
# Đề: Cho các cuộc họp [start, end); cần ít nhất bao nhiêu phòng để không trùng.
# Ràng buộc: end > start.
# Ý tưởng: Coi start là +1, end là -1; sắp theo thời gian, đếm chồng lấn tối đa.
# Độ phức tạp: Time O(n log n) / Space O(n).
# Thực tế: Lập lịch tài nguyên (phòng họp, CPU, làn đường).


def min_meeting_rooms(meetings):
    events = []
    for s, e in meetings:
        events.append((s, 1))
        events.append((e, -1))
    events.sort()
    cur = best = 0
    for _, d in events:
        cur += d
        best = max(best, cur)
    return best


if __name__ == "__main__":
    # Test case
    assert min_meeting_rooms([(0, 30), (5, 10), (15, 20)]) == 2
    assert min_meeting_rooms([(7, 10), (2, 4)]) == 1

    print("OK")
