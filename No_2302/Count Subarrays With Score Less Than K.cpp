class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ret = 0;
        
        vector<long long> preSum(n+1);
        for(int i=0; i<n; i++) {
            preSum[i+1] = preSum[i] + nums[i];
        }
        
        int left = 1;
        for(int i=1; i<n+1; i++) {
            int len = i - left + 1;
            if((preSum[i] - preSum[left-1]) * len < k) {
                ret += len;
            } else {
                while(left < i) {
                    left++;
                    len = i - left + 1;
                    if((preSum[i] - preSum[left-1]) * len < k) {
                        ret += len;
                        break;
                    }
                }
            }
        }
        
        return ret;
    }
};