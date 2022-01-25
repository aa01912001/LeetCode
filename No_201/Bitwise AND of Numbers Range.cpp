class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long ret = left;
        long tmp = left;
        int index = 0;
        while(tmp) {
            if(tmp%2 == 1) {
                long p = pow(2, index+1);
                long comp = ((left>>(index+1))<<(index+1))+p;
                if(comp <= right) {
                    ret -= pow(2, index);
                }
            }
            index++;
            tmp/=2;
        }
        return ret;
    }
};