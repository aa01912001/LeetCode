class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ret = 0, l = -1, r = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) l = i;
            if (nums[i] >= left) r = i;
            ret += r - l;
        }
        
        return ret;
    }
};