class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        sort(nums.begin(), nums.end());
        
        int preSum = 0;
        for (int i=0; i<nums.size(); i++) {
            nums[i] -= preSum;
            if (nums[i] > 0) {
                ret++;
                preSum += nums[i];
                if (preSum >= nums[n-1]) return ret;
            }
        }
        
        return ret;
    }
};