class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1);
        dp[1] = 1;
        int ret = dp[1];
        for(int i=2; i<=n; i++) {
            if(i%2 == 0) {
                dp[i] = dp[i/2];
            } else {
                dp[i] = dp[i/2] + dp[i/2 + 1];
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};