class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                hmap[nums[j]&nums[i]]++;
            }
        }
        
        int ret = 0;
        for(int i=0; i<nums.size(); i++) {
            for(auto t : hmap) {
                if((nums[i]&t.first) == 0) {
                    ret += t.second;
                }
            }
        }
        
        return ret;
            
    }
};