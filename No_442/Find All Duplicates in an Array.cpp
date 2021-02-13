class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        
        for(int i=0; i<nums.size(); i++) {
            int value = abs(nums[i]);
            if(nums[value - 1] < 0) {
                ret.push_back(value);
            }else {
                nums[value - 1] *= -1;
            }
        }
        
        return ret;
    }
};