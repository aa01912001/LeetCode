class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size()+1;
        int n = B.size()+1;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        int ret = 0;
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }
      
        return ret;
    }
};