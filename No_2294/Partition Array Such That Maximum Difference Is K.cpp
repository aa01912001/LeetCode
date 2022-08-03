class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int minValue = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]-minValue > k) {
                minValue = nums[i];
                ret++;
            }
        }
        return ret + 1;
    }
};