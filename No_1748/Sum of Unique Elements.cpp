class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++) {
            umap[nums[i]]++;
        }
        
        int ret = 0;
        for(auto p : umap) {
            if(p.second == 1) ret += p.first;
        }
        
        return ret;
    }
};