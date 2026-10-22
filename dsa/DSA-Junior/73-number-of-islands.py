# 73 - Number of Islands | Đếm số đảo trong lưới 0/1
# Đề: Đếm số cụm ô '1' nối nhau theo 4 hướng.
# Ràng buộc: Lưới ký tự '0'/'1' không rỗng.
# Ý tưởng: DFS/flood fill, đánh dấu ô đã thăm bằng cách đổi '1' -> '0'.
# Độ phức tạp: Time O(R*C) / Space O(R*C).
# Thực tế: Đếm thành phần liên thông trên lưới (xử lý ảnh, bản đồ).


def num_islands(grid):
    g = [row[:] for row in grid]
    R, C = len(g), len(g[0])

    def dfs(i, j):
        if i < 0 or j < 0 or i >= R or j >= C or g[i][j] != '1':
            return
        g[i][j] = '0'
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i, j - 1)

    count = 0
    for i in range(R):
        for j in range(C):
            if g[i][j] == '1':
                count += 1
                dfs(i, j)
    return count


if __name__ == "__main__":
    # Test case
    grid = [['1', '1', '0', '0'], ['1', '0', '0', '1'], ['0', '0', '1', '1']]
    assert num_islands(grid) == 2

    print("OK")
