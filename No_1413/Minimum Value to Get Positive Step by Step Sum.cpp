class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ret = 0;
        int preSum = 0;
        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            ret = min(ret, preSum);
        }
        
        return abs(ret) + 1;
    }
};