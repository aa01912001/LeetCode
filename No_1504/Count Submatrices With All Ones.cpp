class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // dp[i][j] stores the number of continous 1 above mat[i][j]
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0)); 
        int ret = 0;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(i-1 >= 0 && mat[i][j] == 1) { 
                    int t = j;
                    dp[i][j] = dp[i-1][j] + 1;
                    int mn = dp[i][j];
                    while(t >= 0 && mat[i][t] != 0) { // find all possible upper-left submatrices including mat[i][j]. 
                        mn = min(mn, dp[i][t]);
                        ret += mn;
                        t--;
                    }
                } else if(mat[i][j] != 0) {
                    int t = j;
                    while(t >= 0 && mat[i][t] != 0) { // find all possible upper-left submatrices including mat[i][j]. 
                        ret++;
                        t--;
                    }
                    dp[i][j] = 1;
                }
            }
        }
        
        return ret;
    }
};