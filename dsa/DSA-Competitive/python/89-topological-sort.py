# 89 - Topological Sort | Sắp xếp topo (Kahn) trên DAG
# Đề: Trả về một thứ tự sao cho mọi cạnh u->v thì u đứng trước v.
# Ràng buộc: Đồ thị có hướng, không chu trình (DAG).
# Ý tưởng: Kahn - lặp lấy đỉnh có bậc vào 0 (min-heap cho kết quả xác định).
# Độ phức tạp: Time O((V + E) log V) / Space O(V + E).
# Thực tế: Lập lịch phụ thuộc (build, khóa học tiên quyết).

import heapq


def topo_sort(n, edges):
    adj = [[] for _ in range(n)]
    indeg = [0] * n
    for u, v in edges:
        adj[u].append(v)
        indeg[v] += 1
    q = [i for i in range(n) if indeg[i] == 0]
    heapq.heapify(q)
    order = []
    while q:
        u = heapq.heappop(q)
        order.append(u)
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                heapq.heappush(q, v)
    return order


if __name__ == "__main__":
    # Test case
    o = topo_sort(6, [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)])
    pos = {v: i for i, v in enumerate(o)}
    assert len(o) == 6
    assert pos[5] < pos[2] < pos[3] < pos[1] and pos[4] < pos[0]

    print("OK")
