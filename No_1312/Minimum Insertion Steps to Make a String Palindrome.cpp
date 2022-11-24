class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = 0;    
        }
        
        for(int i=1; i<n-1; i++) {
            dp[i][i-1] = 0;
        }
    
        for(int i=1; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                int m = INT_MAX;
                m = min(m, dp[j+1][j+i]+1);
                m = min(m, dp[j][j+i-1]+1);
                if(s[j] == s[j+i]) {
                    m = min(m, dp[j+1][j+i-1]);
                } else {
                    m = min(m, dp[j+1][j+i-1]+2);
                }
                dp[j][j+i] = m;
            }
        }
        return dp[0][n-1];
    }
};