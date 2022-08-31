class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(int i=0; i<nums.size(); i++) {
            if(hset.find(nums[i]) != hset.end()) {
                return true;
            } else {
                hset.insert(nums[i]);
            }
        }
        return false;
    }
};