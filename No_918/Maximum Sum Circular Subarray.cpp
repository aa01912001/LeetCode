class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        int localMax = 0, localMin = 0;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            localMax = max(nums[i], localMax+nums[i]);
            mx = max(mx, localMax);
            localMin = min(nums[i], localMin+nums[i]);
            mn = min(mn, localMin);
            sum += nums[i];
        }

        return sum - mn == 0 ? mx : max(sum-mn, mx);
    }
};