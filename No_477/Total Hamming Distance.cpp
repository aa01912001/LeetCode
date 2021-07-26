class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count(32, 0);
        int ret = 0;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int c = 0;
            while(c <= 31) {
                int b = num % 2;
                if(b == 1) {
                    ret += i - count[c];
                    count[c]++;
                } else {
                    ret += count[c];
                }
                num /= 2;
                c++;
            }
        }
        
        return ret;
    }
};