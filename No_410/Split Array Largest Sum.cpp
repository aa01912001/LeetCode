class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = INT_MAX;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, m, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return high;
    }
    
    bool isPossible(vector<int>& nums, int k, int target) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > target) {
                return false;
            } else {
                if(sum + nums[i] > target) {
                    k--;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
        }
        k--;
        
        return k >= 0;
    }
};