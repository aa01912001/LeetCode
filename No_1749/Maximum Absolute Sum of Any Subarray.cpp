class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(2));
        int ansMin = abs(nums[0]);
        int ansMax = abs(nums[0]);
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int tmp1 = dp[i-1][0] + nums[i];
            int tmp2 = dp[i-1][1] + nums[i];
            dp[i][0] = min(tmp1, nums[i]);
            dp[i][1] = max(tmp2, nums[i]);
            ansMin = min(ansMin, dp[i][0]);
            ansMax = max(ansMax, dp[i][1]);
        }
        
        return max(abs(ansMin), abs(ansMax));
    }
};