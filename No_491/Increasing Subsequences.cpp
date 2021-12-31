class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> hset;
        vector<int> tmp;
        backtraking(0, tmp, nums, hset);
        
        vector<vector<int>> ret;
        for(auto v : hset) {
            ret.push_back(v);
        }
        return ret;
    }
    
    void backtraking(int index, vector<int>& tmp, vector<int>& nums, set<vector<int>>& hset) {
        if(tmp.size() > 1) hset.insert(tmp);
        
        for(int i=index; i<nums.size(); i++) {
            if(tmp.empty() || nums[i] >= tmp.back()) {
                tmp.push_back(nums[i]);
                backtraking(i+1, tmp, nums, hset);
                tmp.pop_back();
            }
        }
        return;
    }
};