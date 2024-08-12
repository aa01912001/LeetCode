class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> hmap;
        
        for (int num : nums)
            hmap[num]++;
        
        for (auto p : hmap) {
            if (p.second == 2)
                ret ^= p.first;
        }
        
        return ret;
    }
};