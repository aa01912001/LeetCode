class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int toLeft = 1000, toRight = 1000;
        for(int i=start; i>=0; i--) {
            if(nums[i] == target) {
                toLeft = start - i;
                break;
            }
        }
        
        for(int i=start+1; i<nums.size(); i++) {
            if(nums[i] == target) {
                toRight = i - start;
                break;
            }
        }
        
        return min(toLeft, toRight);
    }
};