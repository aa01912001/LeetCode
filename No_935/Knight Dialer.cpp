class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> possiblePre = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        int MOD = 1e9 + 7;
        
        vector<vector<int>> dp(n, vector<int>(10));
        for(int i=0; i<10; i++) dp[0][i] = 1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<possiblePre[j].size(); k++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][possiblePre[j][k]]) % MOD;
                }
            }
        }
        
        int ret = 0;
        for(int i=0; i<10; i++) {
            ret = (ret + dp[n-1][i]) % MOD;
        }
        
        return ret;
    }
};