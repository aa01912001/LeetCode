class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0) return false;
        int ret = 1;
        while(num > 1) {
            if(num % 2 == 1) ret++;
            num /= 2;
            ret++;
        }
        
        return ret;
    }
};