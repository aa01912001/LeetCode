class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int left = 1, right = INT_MAX;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i=0; i<n; i++) {
                if(nums[i] > mid) {
                    count += ceil((nums[i] / (double)mid)) - 1;
                }
            }
            if(count > maxOperations) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};