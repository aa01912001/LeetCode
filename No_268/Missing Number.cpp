class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int remaining = (1 + n) * n / 2;
        for(int i=0; i<n; i++) {
            remaining -= nums[i];
        }
        return remaining;
    }
};