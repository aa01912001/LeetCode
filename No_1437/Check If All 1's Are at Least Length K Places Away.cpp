class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                pos = i;
                break;
            }
        }
        
        for(int i=pos+1; i<nums.size(); i++) {
            if(nums[i] == 1) {
                if(i - pos - 1 < k) return false;
                pos = i;
            }
        }
        
        return true;
    } 
};