# 93 - Floyd-Warshall | Đường ngắn nhất giữa mọi cặp đỉnh
# Đề: Tính ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh.
# Ràng buộc: Đồ thị nhỏ (V <= vài trăm); không có chu trình âm.
# Ý tưởng: DP qua đỉnh trung gian k - thử đường i -> k -> j.
# Độ phức tạp: Time O(V^3) / Space O(V^2).
# Thực tế: Đồ thị nhỏ cần khoảng cách mọi cặp; cài đặt ngắn gọn.

INF = float("inf")


def floyd(d):
    d = [row[:] for row in d]
    n = len(d)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]
    return d


if __name__ == "__main__":
    # Test case
    d = [[0, 3, INF, 7], [8, 0, 2, INF], [5, INF, 0, 1], [2, INF, INF, 0]]
    r = floyd(d)
    assert r[0][2] == 5 and r[0][3] == 6 and r[3][1] == 5

    print("OK")
