class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minVal = nums[0];
        int minValForMid = INT_MAX;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > minVal) {
                if(nums[i] > minValForMid)
                    return true;
                else
                    minValForMid = nums[i];
            } else {
                minVal = nums[i];
            }
        }
        return false;
    }
};