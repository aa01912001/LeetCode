class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) continue;
            int gap = nums[i-1] - nums[i] + 1;
            nums[i] += gap;
            ret += gap;
        }
        
        return ret;
    }
};