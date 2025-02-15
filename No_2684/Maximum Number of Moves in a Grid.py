class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [1] * m
        ret = 0

        for col in range(1, n):
            new_dp = [0] * m
            for row in range(m):
                num = grid[row][col]
                if row - 1 >= 0 and num > grid[row-1][col-1] and dp[row-1]:
                    new_dp[row] = 1
                if num > grid[row][col-1] and dp[row]:
                    new_dp[row] = 1
                if row + 1 < m and num > grid[row+1][col-1] and dp[row+1]:
                    new_dp[row] = 1

            dp = new_dp
            if max(dp) == 0:
                break
            ret += 1

        return ret