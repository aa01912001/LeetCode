class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> stk;
        int ret = 0;
        stk.push(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(stk.size() % 2 == 1) {
                // check rule 2
                if(stk.top() == nums[i]) {
                    ret++;
                } else {
                    stk.push(nums[i]);
                }
            } else {
                stk.push(nums[i]);
            }
        }

        // check rule 1
        if(stk.size() % 2 == 1) {
            ret++;
        }

        return ret;
    }
};