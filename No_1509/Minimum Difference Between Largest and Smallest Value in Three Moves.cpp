class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        
        int ret = nums[n-1] - nums[3];
        ret = min(ret, nums[n-2]-nums[2]);
        ret = min(ret, nums[n-3]-nums[1]);
        ret = min(ret, nums[n-4]-nums[0]);
        return ret;
    }
};