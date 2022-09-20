class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = -1, right = 0;
        int curZero = 0;
        int ret = 0;
        while(right < n) {
            if(nums[right] == 0) {
                curZero++;
                if(curZero > k) {
                    while(nums[++left] != 0);
                    curZero--;
                }
            }
            ret = max(ret, right-left);
            right++;
        }
        ret = max(ret, right-left-1);
        return ret;
    }
};