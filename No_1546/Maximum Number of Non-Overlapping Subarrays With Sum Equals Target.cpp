class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        hmap[0] = -1; // dummy
        int ret = 0;
        int last = -1;
        int preSum = 0;
        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            if(hmap.find(preSum-target) != hmap.end()) {
                if(hmap[preSum-target]+1 > last) {
                    last = i;
                    ret++;
                }
            }
            hmap[preSum] = i;
        }
        return ret;
    }
};