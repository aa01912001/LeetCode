class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sum(n, vector<int>(2));
        
        int leftSum = 0;
        for(int i=0; i<n; i++) {
            sum[i][0] = leftSum;
            leftSum += nums[i];
        }
        
        int rightSum = 0;
        for(int i=n-1; i>=0; i--) {
            sum[i][1] = rightSum;
            rightSum += nums[i];
        }
        
        for(int i=0; i<n; i++) {
            if(sum[i][0] == sum[i][1]) return i;
        }
        
        return -1;
    }
};