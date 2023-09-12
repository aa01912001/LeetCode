class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hset(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!hset.count(nums[i])) continue;
            hset.erase(nums[i]);
            int pre = nums[i] - 1, next = nums[i] + 1;
            while (hset.count(pre)) hset.erase(pre--);
            while (hset.count(next)) hset.erase(next++);
            ret = max(ret, next - pre - 1);
        }
        return ret;
    }
    
};