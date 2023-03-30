class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ret = 0;
        int count = 0;
        
        for (int i=0; i<n; i++) {
           if (nums[i] == 0) {
               count++;
               ret += count;
           } else {
               count = 0;
           }
        }
        
        return ret;
    }
};