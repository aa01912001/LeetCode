class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ret = 0;
        int sum = 0;
        unordered_map<int, int> hmap;
        hmap[0] = -1;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if(hmap.count(sum)) {
                ret = max(ret, i-hmap[sum]);
            } else {
                hmap[sum] = i;
            }
        }
        
        return ret;
    }
};