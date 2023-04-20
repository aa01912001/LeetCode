class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int ret = 0;
        int digit = n % 10; n /= 10;
        int exp = 1;
        ret = digit;
        while (n != 0) {
            int preDigit = ret / pow(10, exp-1);
            int base = pow(10, exp);
            digit = n % 10; n /= 10;
            if (digit <= preDigit) {
                ret += digit * base;
            } else {
                ret /= base;
                ret *= base;
                ret += digit * base - 1;
            }
            exp++;
        }
        
        return ret;
    }
};