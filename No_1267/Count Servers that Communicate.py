class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row_count = [sum(row) for row in grid]
        column_count = [sum(column) for column in zip(*grid)]

        return sum(
            1
            for i in range(m)
            for j in range(n)
            if grid[i][j] == 1 and row_count[i] + column_count[j] > 2
        )