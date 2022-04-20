class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count[501] = {};
        for(int i=0 ; i<nums.size(); i++) {
            count[nums[i]] ^= 1;
        }
        
        for(int i=1; i<=500; i++) {
            if(count[i] != 0) return false;
        }
        
        return true;
    }
};