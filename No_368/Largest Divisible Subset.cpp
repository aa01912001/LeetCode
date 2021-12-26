class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        dp[0] = {nums[0]};
        
        vector<int> ret = {nums[0]};
        for(int i=1; i<n; i++) {
            dp[i] = {nums[i]};
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j] == 0 && dp[j].size() >= dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
                if(ret.size() < dp[i].size()) {
                    ret = dp[i];
                }
            }
        }
        return ret;
    }
};