class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i][j]: max avg sum of first j elements partitioned into i groups
        vector<vector<double>> dp(k, vector<double>(n, 0));
        
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        
        
        for(int i=0; i<n; i++) {
            dp[0][i] = nums[i] / (double)(i + 1);
        }
        
        for(int i=1; i<k; i++) {
            for(int j=0; j<n; j++) {
                for(int t=i-1
                    ; t<j; t++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][t] + (nums[j]-nums[t])/(double)(j-t));
                }
            }
        }
        
        return dp[k-1][n-1];
    }
};