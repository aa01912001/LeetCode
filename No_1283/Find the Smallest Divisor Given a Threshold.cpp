class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int result = 0;
            for(int i=0; i<nums.size(); i++) {
                result += ceil((float)nums[i]/mid);
            }
            if(result <= threshold) {
                high = mid - 1;
            } else if(result > threshold) {
                low = mid + 1;
            }
        }
        return low;
    }
};