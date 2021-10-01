class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        int m = 0;
        for(int i=0; i<nums.size(); i++) {
            int t = 0;
            while(nums[i] != 0) { // try to reverse nums[i] to 0
                if(nums[i]%2 == 1) { // op == 0 occurs
                    nums[i] -= 1;
                    ret++;
                    continue;
                }
                nums[i] /= 2;
                t++;
            }
            m = max(m, t); // find the most occurence of op == 2
        }
    
        return ret + m;
        
    }
};