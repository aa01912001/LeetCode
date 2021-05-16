class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int p2 = 1;
        int ret = 0;
        int tmp = nums[0];
        for(; p2<nums.size(); p2++) {
            if(nums[p2] > nums[p2-1]) {
                tmp += nums[p2];
            } else {
                ret = max(ret, tmp);
                tmp = nums[p2];
            }
        }
        
        ret = max(ret, tmp);
        return ret;
    }
};