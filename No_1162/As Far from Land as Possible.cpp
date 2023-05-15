class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        long long ret = -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, INT_MAX));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (j - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    if (i - 1 >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    }
                }
            }
        }
        
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (j + 1 < n)
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                    if (i + 1 < m) {
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    }
                    if (dp[i][j] < INT_MAX)
                        ret = max(ret, dp[i][j]);
                }
            }
        }
        
        return ret;
    }
};