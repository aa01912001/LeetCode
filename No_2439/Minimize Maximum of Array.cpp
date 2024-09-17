class Solution {
public:
    bool checkSatisfied(vector<int>& nums, int target) {
        long long carry = 0;
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] + carry <= target) {
                carry = 0;
                continue;
            }
            carry = (nums[i] + carry) - target;
        }
        
        return nums[0] + carry <= target ? true : false;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0, high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (checkSatisfied(nums, mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        return high;
    }
};