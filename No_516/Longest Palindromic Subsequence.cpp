class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.length();
        int dp[size+1][size+1];
        for(int i=0; i<=size; i++) {
            for(int j=0; j<=size; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i=1; i<=size; i++) {
            for(int j=1; j<=size; j++) {
                int same = 0;
                if(s[size-i] == s[j-1]) same++;
                dp[i][j] = max(dp[i-1][j-1]+same, max(dp[i][j-1], dp[i-1][j]));    
            }
        }
        
        return dp[size][size];
    }
};