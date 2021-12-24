class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ret = 0;
        vector<vector<int>> dp(n, vector<int>(2)); // dp[i][0]: even, dp[i][1]: odd
        dp[0][arr[0]%2] = 1;
        ret += dp[0][1];
        
        for(int i=1; i<n; i++) {
            if(arr[i]%2 == 0) {
                dp[i][0] += dp[i-1][0] + 1;
                dp[i][1] += dp[i-1][1];
            } else {
                dp[i][0] += dp[i-1][1];
                dp[i][1] += dp[i-1][0] + 1;
            }
            ret = (ret + dp[i][1]) % 1000000007;
        }
        
        return ret;
    }
};