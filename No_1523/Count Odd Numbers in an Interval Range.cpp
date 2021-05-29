class Solution {
public:
    int countOdds(int low, int high) {
        int ret = 0;
        int range = high-low;
        if(range % 2 == 0) {
            ret += range/2;
        } else {
            if(low % 2 == 0) {
                ret += range/2 + 1;
            } else {
                ret += range/2;
            }
        }
        
        return low % 2 == 0 ? ret : ret+1;
    }
};