class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mx(n, vector<int>(n, 0)); // mx[i][j]: max value from arr[i] to arr[j]
        for(int i=0; i<n; i++) { 
            int m = 0;
            for(int j=i; j<n; j++) {
                m = max(m, arr[j]);
                mx[i][j] = m;
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j]: mst from arr[i] tp arr[j]
        
        return findMCT(0, n-1, mx, dp);
    }
    
    int findMCT(int s, int e, vector<vector<int>>& mx, vector<vector<int>>& dp) {
        if(s == e) {
            return 0;
        }
        
        int mct = INT_MAX;
        for(int i=s; i<=e-1; i++) { // traverse all possible division of left leaf group and right leaf group 
            int lmax = mx[s][i];
            int rmax = mx[i+1][e];
            int lgroup = dp[s][i] != 0 ? dp[s][i] : findMCT(s, i, mx, dp);
            int rgroup = dp[i+1][e] != 0 ? dp[i+1][e] : findMCT(i+1, e, mx, dp);
            mct = min(mct, lgroup+rgroup+(lmax*rmax));
        }
        
        dp[s][e] = mct; // put mct of arr[s] to arr[e] into dp array 
        
        return dp[s][e];
    }
};