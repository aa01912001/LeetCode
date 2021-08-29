class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int allSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            allSum += nums[i];
        }
        
        int preSum = 0;
        for(int i=0; i<nums.size(); i++) {
            allSum -= nums[i];
            if(preSum == allSum) return i;
            preSum += nums[i];
        }
        
        return -1;
    }
};