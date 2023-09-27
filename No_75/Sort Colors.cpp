class Solution {
public:
    void sortColors(vector<int>& nums) {
        int indexZero = -1, indexTwo = nums.size();
        for (int i = 0; i < indexTwo;) {
            if (nums[i] == 0) {
                swap(nums[++indexZero], nums[i]);
            } else if (nums[i] == 2) {
                swap(nums[--indexTwo], nums[i]);
            }
            
            if (i == indexZero || nums[i] == 1) i++;
        }
        
        return;
    }
};