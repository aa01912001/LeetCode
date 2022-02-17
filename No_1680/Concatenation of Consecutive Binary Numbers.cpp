class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ret = 0;
        for(int i=1; i<=n; i++) {
            ret <<= getBinaryLen(i);
            ret |= i;
            ret %= mod;
        }
        
        return ret;
    }
    
    int getBinaryLen(int num) {
        int len = 0;
        while(num) {
            len++;
            num /= 2;
        }
        
        return len;
    }
};