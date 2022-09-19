class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++) // initialize dp array of first layer with cell value
            dp[0][i] = grid[0][i];
        
        for(int i=1; i<m; i++) { // for each layer
            for(int j=0; j<n; j++) { // for each cell of i layer
                for(int k=0; k<n; k++) { // update dp[i][j] from dp[i-1][0] to dp[i-1][n-1]
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][k]+moveCost[grid[i-1][k]][j]);   
                }  
            }
        }
        
        int ret = INT_MAX;
        for(int i=0; i<n; i++) // get minimum path cost
            ret = min(ret, dp[m-1][i]);
        
        return ret;
    }
};