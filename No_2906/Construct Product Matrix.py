class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        MOD = 12345
        n, m = len(grid), len(grid[0])
        size = n * m
        
        arr = [grid[i][j] for i in range(n) for j in range(m)]
        
        prefix = [1] * size
        postfix = [1] * size
        
        for i in range(1, size):
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD
        
        for i in range(size-2, -1, -1):
            postfix[i] = (postfix[i+1] * arr[i+1]) % MOD
        
        ans = [[0] * m for _ in range(n)]
        for idx in range(size):
            ans[idx // m][idx % m] = (prefix[idx] * postfix[idx]) % MOD
        
        return ans