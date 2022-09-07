class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return 0;
        uint32_t ret = 0;
        int shiftCount = 0;
        while(n != 0) {
            ret <<= 1;
            ret += n % 2;
            n >>= 1;
            shiftCount++;
        }
        ret <<= 32 - shiftCount;
        return ret;
    }
};