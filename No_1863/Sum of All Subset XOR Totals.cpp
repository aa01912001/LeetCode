class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return traverseAllSubset(nums, 0, 0);
    }
    
    int traverseAllSubset(vector<int>& nums, int i, int tmpXor) {
        if(i == nums.size()) return tmpXor;
        
        return traverseAllSubset(nums, i+1, tmpXor) + traverseAllSubset(nums, i+1, tmpXor^nums[i]);
    }
};