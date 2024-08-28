class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        def dfs(grid, dp, i, j):
            if (i, j) in dp:
                return dp[(i, j)]
            
            path_count = 0
            if i - 1 >= 0 and grid[i-1][j] < grid[i][j]:
                path_count += dfs(grid, dp, i-1, j)
            if i + 1 < len(grid) and grid[i+1][j] < grid[i][j]:
                path_count += dfs(grid, dp, i+1, j)
            if j - 1 >= 0 and grid[i][j-1] < grid[i][j]:
                path_count += dfs(grid, dp, i, j-1)
            if j + 1 < len(grid[0]) and grid[i][j+1] < grid[i][j]:
                path_count += dfs(grid, dp, i, j+1)
        
            
            dp[(i,j)] = path_count + 1
            return dp[(i,j)]
            
        ret = 0
        dp = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ret += dfs(grid, dp, i, j)
                
        return ret % (10**9 + 7)