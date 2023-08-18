class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int ret = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int prod = nums[i] * nums[j];
                ret += hmap[prod] * 8;
                hmap[prod]++;
            }
        }
        
        return ret;
    }
};