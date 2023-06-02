class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ret = 0;
        int n = nums.size();
        for (int i=0; i<=n; i++) {
            long long from = i == 0 ? 1 : nums[i-1] + 1;
            long long to;
            if (i == n) {
                to = nums[i-1] + k;
            } else {
                if (i == 0) {
                    to = min(k, nums[i]-1);                    
                } else {
                    to = min(nums[i-1]+k, nums[i]-1);
                }
            }
        
            if (from <= to) {
                ret += sum(from, to);
                k -= to - from + 1;
            }
            if (k == 0) break;
        }
        return ret;
    }
    
    long long sum(long long from, long long to) {
        return (from + to) * (to - from + 1) / 2.;
    }
};