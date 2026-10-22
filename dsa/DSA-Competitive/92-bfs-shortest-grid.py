# 92 - BFS Shortest Path (grid) | Đường ngắn nhất trên lưới 0/1
# Đề: Số bước ít nhất từ (0,0) tới (R-1,C-1), đi 4 hướng, ô 1 là tường; -1 nếu bí.
# Ràng buộc: Lưới không rỗng.
# Ý tưởng: BFS lan theo lớp trên đồ thị lưới không trọng số.
# Độ phức tạp: Time O(R*C) / Space O(R*C).
# Thực tế: Tìm đường mê cung, khoảng cách ngắn nhất không trọng số.

from collections import deque


def bfs_grid(g):
    R, C = len(g), len(g[0])
    if g[0][0] or g[R - 1][C - 1]:
        return -1
    dist = [[-1] * C for _ in range(R)]
    dist[0][0] = 0
    q = deque([(0, 0)])
    while q:
        r, c = q.popleft()
        if r == R - 1 and c == C - 1:
            return dist[r][c]
        for nr, nc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
            if 0 <= nr < R and 0 <= nc < C and not g[nr][nc] and dist[nr][nc] < 0:
                dist[nr][nc] = dist[r][c] + 1
                q.append((nr, nc))
    return -1


if __name__ == "__main__":
    # Test case
    assert bfs_grid([[0, 0, 0], [1, 1, 0], [0, 0, 0]]) == 4
    assert bfs_grid([[0, 1], [1, 0]]) == -1

    print("OK")
