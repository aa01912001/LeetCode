class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 2) return true;
        bool inFlag = true, deFlag = true;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i]) inFlag = false;
            if(nums[i-1] < nums[i]) deFlag = false;
            if(!inFlag && !deFlag) return false;
        }
        
        return true;
    }
};