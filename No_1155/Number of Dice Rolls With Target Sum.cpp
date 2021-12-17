typedef long long ll;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n, vector<ll>(target+1, 0));
        for(int i=1; i<=k; i++) {
            if(i > target) break;
            dp[0][i] = 1;
        }
        
        int mod = 1e9 + 7;
        for(int i=1; i<n; i++) {
            for(int j=1; j<=k; j++) {
                for(int t=1; t<=target; t++) {
                    if(dp[i-1][t] != 0) {
                        if(t+j > target) break;
                        dp[i][t+j] += dp[i-1][t] % mod;
                    }
                }
            }
        }
        
        return dp[n-1][target] % mod;
    }
};