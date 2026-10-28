class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        pre_dp = []
        
        for i in range(m):
            cur_dp = []
            for j in range(n):
                s = set()
                
                if i > 0:
                    s.update(grid[i][j] ^ v for v in pre_dp[j])

                if j > 0:
                    s.update(grid[i][j] ^ v for v in cur_dp[-1])

                if i == 0 and j == 0:
                    s.add(grid[i][j])
                    
                cur_dp.append(s)
            pre_dp = cur_dp
            
        return min(pre_dp[-1])