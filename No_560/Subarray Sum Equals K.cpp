class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int ret = 0, sum = 0;
        int i=0;
        while(i < nums.size()) {
            sum += nums[i];
            if(sum == k) ret++; // if the sum of nums[0] ~ nums[i] equals to k
            if(hmap.find(sum-k) != hmap.end()) { // the sum of nums[x] ~ nums[i] equals to k
                ret += hmap[sum-k];    
            }
            hmap[sum]++; // store the sum of nums[0] ~ nums[i]
            i++;
        }
        
        return ret;
    }
};