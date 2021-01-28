class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int index;
        for(int i=0; i<nums.size(); i++) { // find the index where the value of nums[index] is greater equal than zero
            if(nums[i] >= 0) {
                index = i;
                break;
            }
        }
        
        int i, j;
        for(i=index-1, j=index; i>=0 && j<nums.size();) {
            if(-1*nums[i] >= nums[j]) {
                ret.push_back(nums[j]*nums[j]);
                j++;
            }else {
                ret.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        
        while(i >= 0) {
            ret.push_back(nums[i]*nums[i]);
            i--;
        }
        
         while(j < nums.size()) {
            ret.push_back(nums[j]*nums[j]);
            j++;
        }
        
        return ret;
    }
};