# 45 - Plus One | Cộng 1 vào số biểu diễn bằng mảng chữ số
# Đề: Mảng chữ số (đầu là hàng cao nhất) + 1, ví dụ [1,2,3]->[1,2,4], [9,9]->[1,0,0].
# Ràng buộc: Mỗi phần tử là chữ số 0..9.
# Ý tưởng: Cộng từ cuối, xử lý nhớ; nếu nhớ vượt đầu thì chèn 1 lên đầu.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Cộng số lớn vượt kiểu nguyên (big number).


def plus_one(d):
    d = d[:]
    for i in range(len(d) - 1, -1, -1):
        if d[i] < 9:
            d[i] += 1
            return d
        d[i] = 0
    return [1] + d


if __name__ == "__main__":
    # Test case
    assert plus_one([1, 2, 3]) == [1, 2, 4]
    assert plus_one([9, 9]) == [1, 0, 0]

    print("OK")
