class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        long long ret = 1;
        for (int i = 2; i <= n; i++) {
            ret = ret * i % MOD;
            ret = ret * (2*i-1) % MOD;
        }
        
        return ret;
    }
};