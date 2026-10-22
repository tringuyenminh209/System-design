# 88 - Dijkstra | Đường đi ngắn nhất từ một đỉnh (trọng số không âm)
# Đề: Tính khoảng cách ngắn nhất từ src tới mọi đỉnh.
# Ràng buộc: Trọng số cạnh >= 0.
# Ý tưởng: Hàng đợi ưu tiên (heap) luôn lấy đỉnh gần nhất chưa xử lý để nới lỏng.
# Độ phức tạp: Time O((V + E) log V) / Space O(V).
# Thực tế: Định tuyến, bản đồ, mạng lưới.

import heapq


def dijkstra(n, adj, src):
    dist = [float("inf")] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist


if __name__ == "__main__":
    # Test case
    adj = {0: [(1, 1), (2, 4)], 1: [(2, 2), (3, 6)], 2: [(3, 3)], 3: []}
    d = dijkstra(4, adj, 0)
    assert d == [0, 1, 3, 6]

    print("OK")
