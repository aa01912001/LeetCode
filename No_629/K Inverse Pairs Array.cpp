class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[n][k] = dp[n-1][k] + dp[n-1][k-1] + dp[n-1][k-2] + ... + dp[n-1][k-min(k, n-1)]
        const int MOD = 1e9 + 7;
        vector<int> dp(k+1);
        dp[0] = 1;
    
        vector<int> preSum(k+1, 1);
        for (int i = 2; i <= n; i++) {
            vector<int> cur(k+1, 1);
            for (int j = 1; j <= k; j++) {
                int index = j - min(j, i-1);
                if (index <= 0) {
                    cur[j] = preSum[j];
                } else {
                    cur[j] = (preSum[j] - preSum[index-1] + MOD) % MOD;
                }
                
            }
            dp = cur;
            
            for (int t = 1; t <= k; t++) {
                // to calculate prefix sum for next i
                preSum[t] = ((long long)preSum[t-1] + dp[t]) % MOD;
            }
        }

        return dp[k];
    }
};