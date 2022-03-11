class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int mSum = 0;
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            mSum = (mSum + nums[i]) % k;
            if(hmap.find(mSum) != hmap.end() && i - hmap[mSum] > 1) return true;
            if(mSum == 0 && i >= 1) return true; // if sum of nums[0] ~ nums[i] can be divided by k
            if(hmap.find(mSum) == hmap.end()) hmap[mSum] = i; // if not exists before, insert this remainder
        }
        return false;
    }
};