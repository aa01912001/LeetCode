class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size()-1;
        int i = 0, j = size;
        while(i < j) {
            int mid = (i+j)/2;
            if(mid == 0) {
                if(nums[mid+1] < nums[0]) return 0;
                i = mid + 1;
            } else if(mid == size) {
                if(nums[mid-1] < nums[size]) return size;
                j = mid - 1;
            } else {
                 if(nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]) return mid;
                if(nums[mid-1] < nums[mid+1]) {
                    i = mid+1;
                } else {
                    j = mid-1;
                }     
            }
        }
        
        return i;
    }
};