class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> hset;
            int count = -1;
            for (int j = i; j < nums.size(); j++) {
                if (hset.find(nums[j]) == hset.end()) {
                    if (hset.find(nums[j] - 1) == hset.end() && hset.find(nums[j] + 1) == hset.end())
                        count++;
                    else if (hset.find(nums[j] - 1) != hset.end() && hset.find(nums[j] + 1) != hset.end())
                        count--;
                }
                
                hset.insert(nums[j]);
                ret += count;
            }
        }
        
        return ret;
    }
};