class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        vector<int> ret(2);
        for(int i=0; i<nums.size(); i++) {
            if(hmap.find(target-nums[i]) != hmap.end()) {
                ret[0] = i;
                ret[1] = hmap[target-nums[i]];
            } else {
                hmap[nums[i]] = i;
            }
        }
        return ret;
    }
};