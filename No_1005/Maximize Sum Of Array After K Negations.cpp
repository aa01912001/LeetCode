class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int absMin = 101;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                ret += -1*nums[i];
                k--;
            } else {
                ret += nums[i];   
            }
            if(absMin > abs(nums[i])) absMin = abs(nums[i]);
        }
        
        if(k > 0) {
            if(k%2 == 1) {
                return ret - 2*absMin;
            }
        }
        return ret;
    }
};