class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<int> leftOnes(len), rightOnes(len);
        
        leftOnes[0] = nums[0];
        for(int i=1; i<len; i++) {
            if(nums[i] == 1) {
                leftOnes[i] = leftOnes[i-1] + 1;
            }
        }
        
        rightOnes[len-1] = nums[len-1];
        for(int i=len-2; i>=0; i--) {
            if(nums[i] == 1) {
                rightOnes[i] = rightOnes[i+1] + 1;
            }
        }
        
        int ret = 0;
        for(int i=0; i<len; i++) {
            if(nums[i] == 0) {
                int tmp = 0;
                if(i != 0) tmp += leftOnes[i-1];
                if(i != len-1) tmp += rightOnes[i+1];
                ret = max(ret, tmp);
            }
        }
        
        if(ret == 0) {
            return nums[0] == 0 ? 0 : len-1;
        }
        
        return ret;
    }
};