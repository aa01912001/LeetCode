class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int index = 0, remain = nums[0];
        while(index < len-1 && remain > 0) {
            index++;
            remain = max(remain-1, nums[index]);
        }
        
        return index == len-1 ? true : false;
    }
};