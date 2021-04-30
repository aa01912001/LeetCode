class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i < j) {
            int mid = (i+j)/2;
            int midNum = nums[mid];
            if(midNum == target) return mid;
            
            if(nums[i] <= nums[mid]) { // if left subarray is sorted.
                if(target >= nums[i] && target <= nums[mid]) { // if target is in this range
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
                
                continue;
            } 
            
            if(nums[mid+1] <= nums[j]) { // if right subarray is sorted.
                if(target >= nums[mid+1] && target <= nums[j]) { // if target is in this range
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
                
                continue;
            }
        }
        
        return nums[i] == target ?　i : -1;
    }
};