class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        solve(0, cur, nums, ret);
        return ret;
    }
    
    void solve(int index, vector<int>& cur, vector<int>& nums, vector<vector<int>>& ret) {
        if (index == nums.size()) {
            ret.push_back(cur);
            return;
        }
        
        cur.push_back(nums[index]);
        solve(index+1, cur, nums, ret);
        cur.pop_back();
        solve(index+1, cur, nums, ret);
        return;
    }
};