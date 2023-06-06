class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<unsigned int> dp(n1+1);
        
        for (int i=0; i<n1; i++) {
            if (t[0] == s[i])
                dp[i+1] = dp[i] + 1;
            else 
                dp[i+1] = dp[i];
        }
        
        for (int i=1; i<n2; i++) {
            vector<unsigned int> cur(n1+1);
            for (int j=i; j<n1; j++) {
                if (t[i] == s[j]) {
                    cur[j+1] = dp[j] + cur[j];
                } else {
                    cur[j+1] = cur[j];
                }
            }
            dp = cur;
        }
        
        return dp[n1];
    }
    
};
