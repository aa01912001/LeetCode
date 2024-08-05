class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 1;
        long long sum = nums[0];
        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            sum += nums[right];
            while (sum + k < (long long)nums[right] * (right - left + 1)) {
                sum -= nums[left];
                left++;
            }   
            ret = max(ret, right - left + 1);
        }
        
        return ret;
    }
};