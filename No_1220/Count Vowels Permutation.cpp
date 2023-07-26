class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(5, 1);
        
        for (int i = 2; i <= n; i++) {
            vector<long long> pre = dp;
            dp[0] = (pre[1] + pre[2] + pre[4]) % MOD;
            dp[1] = (pre[0] + pre[2]) % MOD;
            dp[2] = (pre[1] + pre[3]) % MOD;
            dp[3] = (pre[2]) % MOD;
            dp[4] = (pre[2] + pre[3]) % MOD;
        }
        
        return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
    }
};