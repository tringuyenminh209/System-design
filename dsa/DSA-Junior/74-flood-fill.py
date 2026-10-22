# 74 - Flood Fill | Tô màu vùng liên thông
# Đề: Từ ô (sr, sc), đổi mọi ô cùng màu nối nhau sang màu mới.
# Ràng buộc: Lưới không rỗng.
# Ý tưởng: DFS lan theo 4 hướng khi ô có màu gốc.
# Độ phức tạp: Time O(R*C) / Space O(R*C).
# Thực tế: Công cụ "xô sơn" trong ứng dụng vẽ; loang trên lưới.


def flood_fill(image, sr, sc, new_color):
    g = [row[:] for row in image]
    old = g[sr][sc]
    if old == new_color:
        return g
    R, C = len(g), len(g[0])

    def fill(i, j):
        if i < 0 or j < 0 or i >= R or j >= C or g[i][j] != old:
            return
        g[i][j] = new_color
        fill(i + 1, j)
        fill(i - 1, j)
        fill(i, j + 1)
        fill(i, j - 1)

    fill(sr, sc)
    return g


if __name__ == "__main__":
    # Test case
    img = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    assert flood_fill(img, 1, 1, 2) == [[2, 2, 2], [2, 2, 0], [2, 0, 1]]

    print("OK")
