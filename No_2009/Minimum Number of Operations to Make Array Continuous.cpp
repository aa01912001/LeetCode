class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = INT_MAX, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> dNums;
        dNums.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) dNums.push_back(nums[i]); 
        }
        
        int left = 0, right = 0;
        while (right < dNums.size()) {
            if (dNums[right] <= dNums[left] + n - 1) {
                ret = min(ret, n-(right-left+1));
                right++;
            } else {
                left++;
            }
        }
        
        return ret;
    }
};