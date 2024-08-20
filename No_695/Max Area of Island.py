class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(grid, i, j) -> int:
            if i < 0 or i >= len(grid):
                return 0
            if j < 0 or j >= len(grid[0]):
                return 0
            if grid[i][j] == 0:
                return 0
            
            grid[i][j] = 0
            
            return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1)  + dfs(grid, i, j + 1)
        
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    ret = max(ret, dfs(grid, i, j))
                    
        return ret