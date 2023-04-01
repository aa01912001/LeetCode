class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int ret = 0, n = nums.size();
        
        for (int i=0; i<n; i++) {
            hmap[nums[i]]++;
        }
        
        for (auto p : hmap) {
            if (k == 0 && p.second > 1) ret++;
            if (k > 0 && hmap.count(p.first+k)) ret++;
        }
        
        return ret;
    }
};