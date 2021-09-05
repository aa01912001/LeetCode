class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        int sum = 0, ret = 0;
        for(int i=0; i< nums.size(); i++) {
            sum += nums[i];
            ret += freq[sum-goal];
            freq[sum]++;
        }
        
        return ret;
    }
};