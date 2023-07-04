class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ret = 0, dpPos = 0, dpNeg = 0;
        for (int num : nums) {
            if (num < 0) {
                int tmp = dpPos;
                dpPos = dpNeg == 0 ? 0 : dpNeg + 1;
                dpNeg = tmp + 1;
            } else if (num > 0) {
                dpNeg = dpNeg == 0 ? 0 : dpNeg + 1;
                dpPos = dpPos + 1;
            } else {    
                dpNeg = 0;
                dpPos = 0;
            }
            ret = max(ret, dpPos);
        }
        
        return ret;
    }
};