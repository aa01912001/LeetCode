class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0] >= target) return 1;
        if(nums.size() == 1) {
            return nums[0] >= target ? 1 : 0;
        }
        int left = 0, right = 1;
        int tmp = nums[0] + nums[1];
        int ret = INT_MAX;
        while(right < nums.size()) {
            if(tmp >= target) { // if sum of subarray >= target
                ret = min(ret, right-left+1);
                tmp -= nums[left++];
            } else { // if sum of subarray < target
                if(++right == nums.size()) break;
                tmp += nums[right];
            }
        }
        
        if(left == 0 && right == nums.size()) return 0;
        
        return ret;
    }
};