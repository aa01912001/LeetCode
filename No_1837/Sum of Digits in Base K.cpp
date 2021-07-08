class Solution {
public:
    int sumBase(int n, int k) {
        if(n < k) return n;
        int ret = 0;
        while(n >= k) {
            ret += n % k;
            n = n / k;
        }
        
        return ret + n;
    }
};