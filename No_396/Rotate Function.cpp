class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 0a 1b 2c 3d => b 2c 3d 
        // 1a 2b 3c 0d => diff a b c -3d = a b c d -4d
        // 2a 3b 0c 1d => diff a b d -3c = a b c d -4c
        // 3a 0b 1c 2d => diff a c d -3b = a b c d -4b
        // 0a 1b 2c 3d => diff b c d -3a = a b c d -4a
        int n = nums.size();
        int sum = 0, f = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        
        int ret = f;
        for(int i=n-1; i>=0; i--) {
            f += sum + (-1 * n * nums[i]);
            ret = max(ret, f);
        }
        
        return ret;
    }
};