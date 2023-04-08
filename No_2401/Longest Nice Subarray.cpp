class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ret = 1;
        int left = 0, right = 0, tmp = nums[0];
        while (right < n) {
            if (left == right) {
                tmp = nums[left];
                right++;
                continue;
            }
            if ((tmp & nums[right]) == 0) {
                ret = max(ret, right-left+1);
                tmp |= nums[right];
                right++;
            } else {
                tmp ^= nums[left];
                left++;
            }
        }
        
        return ret;
    }
};