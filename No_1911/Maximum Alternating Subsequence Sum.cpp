class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int flag = 0; // 0: to find peak, 1: to find valley
        long long ret = 0;
        for(int i=1; i<nums.size(); i++) {
            if(flag) {
                if(nums[i] > nums[i-1]) {
                    ret -= nums[i-1];
                    flag = 0;
                }
            } else {
                if(nums[i] < nums[i-1]) {
                    ret += nums[i-1];
                    flag = 1;
                }
            }
        }
        
        if(!flag) ret += nums[nums.size()-1];
        
        return ret;
    }
};