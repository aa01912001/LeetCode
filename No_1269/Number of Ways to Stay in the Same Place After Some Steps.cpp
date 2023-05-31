class Solution {
public:
    int numWays(int steps, int arrLen) {
        // dp[i][j]: remaining i steps, at j index
        // trasition: dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]
        const int MOD = 1e9 + 7;
        int n = min(steps, arrLen);
        vector<int> pre(n);
        pre[0] = 1;
        
        for (int i=1; i<=steps; i++) {
            vector<int> dp(n);
            for (int j=0; j<n; j++) {
                dp[j] = (dp[j] + pre[j]) % MOD;
                if (j - 1 >= 0)
                    dp[j] = (dp[j] + pre[j-1]) % MOD;
                if (j + 1 < n)
                    dp[j] = (dp[j] + pre[j+1]) % MOD;
            }
            pre = dp;
        }
        
        return pre[0];
    }
};