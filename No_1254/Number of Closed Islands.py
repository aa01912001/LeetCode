class Solution:

    def closedIsland(self, grid: list[list[int]]) -> int:
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])
        closed_island_count = 0

        def dfs(i: int, j: int) -> bool:
            if i < 0 or j < 0 or i >= m or j >= n:
                return False

            if grid[i][j] == 1 or grid[i][j] == -1:
                return True

            grid[i][j] = -1

            is_closed = True
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                is_closed &= dfs(i + dx, j + dy)

            return is_closed

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    if dfs(i, j):
                        closed_island_count += 1

        return closed_island_count