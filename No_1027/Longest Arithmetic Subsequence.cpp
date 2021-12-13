class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int mx = 2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                if(dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] = dp[j][diff] + 1;
                    mx = max(mx, dp[i][diff]); 
                } else {
                    dp[i][diff] = 2;
                }
            }
        }
        
        return mx;
    }
};