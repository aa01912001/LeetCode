class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret = 0;
        while (target > startValue) {
            target % 2 == 1 ? target += 1 : target /= 2;
            ret++;
        }
        
        return ret + startValue - target;
    }
};