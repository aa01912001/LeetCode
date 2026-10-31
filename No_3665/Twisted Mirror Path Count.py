class Solution:
	def uniquePaths(self, grid: list[list[int]]) -> int:
		m, n = len(grid), len(grid[0])
		MOD = 10**9 + 7
		
		# pre_dp[j] stores the state at column j: [paths_entering_from_left, paths_entering_from_above]
		pre_dp = [[0, 0] for _ in range(n)]
		
		for i in range(m):
			cur_dp = [[0, 0] for _ in range(n)]
			for j in range(n):
				if i == 0 and j == 0:
					cur_dp[j] = [1, 1]
					continue
				
				# Calculate paths entering (i, j) from the left
				if j > 0:
					if grid[i][j - 1] == 0:
						# Moving right from an empty cell enters (i, j) from the left
						cur_dp[j][0] = (cur_dp[j - 1][0] + cur_dp[j - 1][1]) % MOD
					else:
						# Moving right into a mirror reflects downwards, equivalent to entering from above
						cur_dp[j][0] = cur_dp[j - 1][1] % MOD
				
				# Calculate paths entering (i, j) from above
				if i > 0:
					if grid[i - 1][j] == 0:
						# Moving down from an empty cell enters (i, j) from above
						cur_dp[j][1] = (pre_dp[j][0] + pre_dp[j][1]) % MOD
					else:
						# Moving down into a mirror reflects rightwards, equivalent to entering from the left
						cur_dp[j][1] = pre_dp[j][0] % MOD
						
			pre_dp = cur_dp
			
		return (pre_dp[-1][0] + pre_dp[-1][1]) % MOD