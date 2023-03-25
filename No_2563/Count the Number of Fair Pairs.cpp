class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long n = nums.size();
        int left = 0, right = n - 1;
        long long sum1 = 0, sum2 = 0;
        while(left < right) {
            if(nums[left] + nums[right] > upper) {
                sum1 += right - left;
                right--;
            } else {
                left++;
            }
        }
        
        left = 0, right = n - 1;
        while(left < right) {
            if(nums[left] + nums[right] < lower) {
                sum2 += right - left;
                left++;
            } else {
                right--;
            }
        }
        
        long long totalPairs = (n * (n - 1)) / 2;
        return totalPairs - sum1 - sum2;
    }
};