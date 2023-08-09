class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpLeft(n, INT_MAX), dpRight(n, INT_MAX);
        
        dpLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dpLeft[i] = min(dpLeft[i], dpLeft[j]+i-j-1);
                }
            }
            if (dpLeft[i] == INT_MAX) dpLeft[i] = i;
        }
                
        dpRight[n-1] = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    dpRight[i] = min(dpRight[i], dpRight[j]+j-i-1);
                }
            }
            if (dpRight[i] == INT_MAX) dpRight[i] = n - i - 1;
        }
        
        int ret = INT_MAX;
        for (int i = 1; i < n-1; i++) {
            if (dpLeft[i] == i || dpRight[i] == n - i - 1)
                continue;
            ret = min(ret, dpLeft[i]+dpRight[i]);
        }
        
        return ret;
    }
};