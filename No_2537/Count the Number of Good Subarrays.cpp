class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ret = 0;
        unordered_map<int, int> hmap;
        int pairCount = 0;
        
        for(int i=0; i<n; i++) {
            pairCount += hmap[nums[i]];
            hmap[nums[i]]++;
            while(pairCount >= k) {
                ret += (n - i);
                pairCount -= hmap[nums[left]] - 1;
                hmap[nums[left]]--;
                left++;
            }
        }
        
        return ret;
    }
};