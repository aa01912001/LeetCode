class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int width = count(nums.begin(), nums.end(), 1);
        int ret = nums.size();
        int length = nums.size();
        
        int zeros = count(nums.begin(), nums.begin()+width, 0);
        for (int i = 0; i < length; i++) {
            ret = min(ret, zeros);
            if (nums[(i + width) % length] == 0)
                zeros++;
            if (nums[i] == 0)
                zeros--;
        }
        
        return ret;
    }
};