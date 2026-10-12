class Solution:

  def minFlips(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])

        row_flips = sum(
            grid[i][j] != grid[i][c - 1 - j]
            for i in range(r)
            for j in range(c // 2)
        )

        col_flips = sum(
            grid[j][i] != grid[r - 1 - j][i]
            for i in range(c)
            for j in range(r // 2)
        )

        return min(row_flips, col_flips)