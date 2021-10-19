class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0, ret = 0;
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if(mod < 0) mod = k - abs(mod);
            if(mod == 0) ret++;
            ret+= hmap[mod];
            hmap[mod]++;
        }
        
        return ret;
    }
};