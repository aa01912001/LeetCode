class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, len); // dp[i]: minimum jumps needed for nums[i]
        dp[0] = 0;
        for(int i=0; i<len; i++) {
            int tmp = nums[i];
            int j = i+1;
            while(j<len && tmp>0) {
                dp[j] = min(dp[j], dp[i]+1);
                j++;
                tmp--;
            }
        }
        
        return dp[len-1];
    }
};