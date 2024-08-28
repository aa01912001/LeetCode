class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int ret = 0;
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n; j++) {
                ret = (ret + dfs(grid, dp, i, j)) % MOD;
            }
        }
        
        return ret;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int pathCount = 0;
        if (i - 1 >= 0 && grid[i-1][j] < grid[i][j])
            pathCount = (pathCount + dfs(grid, dp, i-1, j)) % MOD;
        if (i + 1 < grid.size() && grid[i+1][j] < grid[i][j])
            pathCount = (pathCount + dfs(grid, dp, i+1, j)) % MOD;
        if (j - 1 >= 0 && grid[i][j-1] < grid[i][j])
            pathCount = (pathCount + dfs(grid, dp, i, j-1)) % MOD;
        if (j + 1 < grid[0].size() && grid[i][j + 1] < grid[i][j])
            pathCount = (pathCount + dfs(grid, dp, i, j+1)) % MOD;
        
        dp[i][j] = pathCount + 1;
        
        return dp[i][j];
    }
};