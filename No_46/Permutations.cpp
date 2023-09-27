class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        backtracking(0, nums, ret);
        return ret;
    }
    
    void backtracking(int index, vector<int>& nums, vector<vector<int>>& ret) {
        if (index == nums.size()) {
            ret.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtracking(index+1, nums, ret);
            swap(nums[index], nums[i]);
        }
        
        return;
    }
};