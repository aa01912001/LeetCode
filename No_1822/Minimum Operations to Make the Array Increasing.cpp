class Solution {
public:
    int arraySign(vector<int>& nums) {
        int mNum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) mNum++;
        }
        
        return (mNum % 2 == 0) ? 1 : -1;
    }
};