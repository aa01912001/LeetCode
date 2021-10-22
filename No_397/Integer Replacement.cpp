class Solution {
public:
    int integerReplacement(int n) {
        long l = n;
        int ret = 0;
        while(l != 1) {
            if(l % 2 == 1) {
                if(l % 4 == 3 && l > 3) {
                    l += 1;
                }
                ret++;
            }
            l /= 2;
            ret++;
        }
        
        return ret;
    }
};