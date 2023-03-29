class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int front = -1, rear = -2, n = nums.size();
        int mx = nums[0], mn = nums[n-1];
        
        for(int i=1; i<n; i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n-1-i]);
            if(nums[i] < mx) rear = i;
            if(nums[n-1-i] > mn) front = n - 1 - i;
        }
        
        return rear - front + 1;
    }
};