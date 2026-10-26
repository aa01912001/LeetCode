class Solution:
	def countIslands(self, grid: list[list[int]], k: int) -> int:
		m, n = len(grid), len(grid[0])
		directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
		
		def dfs(i: int, j: int) -> int:
			if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
				return 0
			
			cur_sum = grid[i][j]
			grid[i][j] = 0
            
			for di, dj in directions:
				cur_sum += dfs(i + di, j + dj)
				
			return cur_sum
		
		ans = 0
		for i in range(m):
			for j in range(n):
				if grid[i][j] != 0 and dfs(i, j) % k == 0:
					ans += 1
					
		return ans