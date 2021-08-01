class Solution {
private:
    unordered_map<int, vector<int>> hmap;
public:
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            hmap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = hmap[target].size();
        return hmap[target][rand() % size];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */