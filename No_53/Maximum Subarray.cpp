class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int preSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            preSum = max(preSum+nums[i], nums[i]);
            ret = max(ret, preSum);
        }
        return ret;
    }
};