class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int ret = 1;
        for(int i=1; i<n; i++) {
            if(arr[i] > arr[i-1]) {
                dp[i][0] = dp[i-1][1] + 1;
                ret = max(ret, dp[i][0]);
            }
            
            if(arr[i] < arr[i-1]) {
                dp[i][1] = dp[i-1][0] + 1;
                ret = max(ret, dp[i][1]);
            }
        }
        return ret;
    }
};