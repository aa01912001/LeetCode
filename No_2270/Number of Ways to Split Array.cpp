class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        long sum = 0, prefixSum = 0; 
        for(int i=0; i<n; i++) sum += nums[i];
        for(int i=0; i<n-1; i++) {
            prefixSum += nums[i];
            sum -= nums[i];
            if(prefixSum >= sum) ret++;
        }
        return ret;
    }
};