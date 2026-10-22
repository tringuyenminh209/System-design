# 58 - Max Consecutive Ones | Số 1 liên tiếp nhiều nhất
# Đề: Trong dãy 0/1, tìm chuỗi số 1 liên tiếp dài nhất.
# Ràng buộc: Phần tử chỉ là 0 hoặc 1.
# Ý tưởng: Đếm chạy hiện tại, reset về 0 khi gặp số 0.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Đo chuỗi trạng thái liên tục (uptime, streak).


def find_max_consecutive_ones(a):
    best = cur = 0
    for x in a:
        cur = cur + 1 if x else 0
        best = max(best, cur)
    return best


if __name__ == "__main__":
    # Test case
    assert find_max_consecutive_ones([1, 1, 0, 1, 1, 1]) == 3
    assert find_max_consecutive_ones([0, 0]) == 0

    print("OK")
