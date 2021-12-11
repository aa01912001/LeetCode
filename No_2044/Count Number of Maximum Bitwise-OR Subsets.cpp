class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> hmap; // OR num : nums of subset
        DFS(0, 0, nums, hmap);
        
        int mx = 0;
        for(auto t : hmap) {
            mx = max(mx, t.first);
        }
        return hmap[mx];
    }
    
    void DFS(int num, int index, vector<int>& nums, unordered_map<int, int>& hmap) {
        if(index == nums.size()) {
            hmap[num]++;
            return;
        }
        
        DFS(num, index+1, nums, hmap);
        DFS(num|nums[index], index+1, nums, hmap);
        return;
    }
};