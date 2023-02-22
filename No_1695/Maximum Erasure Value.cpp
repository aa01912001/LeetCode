class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ret = 0;
        int sum = 0;
        int left = 0, right = 0, n = nums.size();
        unordered_set<int> hset;
        
        while(right < n) {
            if(!hset.count(nums[right])) {
                hset.insert(nums[right]);
                sum += nums[right];
                ret = max(ret, sum);
                right++;
            } else {
                sum -= nums[left];
                hset.erase(nums[left]);
                left++;
            }
        }
        
        return ret;
    }
};