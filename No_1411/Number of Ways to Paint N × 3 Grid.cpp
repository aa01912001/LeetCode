class Solution {
public:
    int numOfWays(int n) {
        long long pattern1 = 6, pattern2 = 6;
        const int MOD = 1e9 + 7;
        n--;
        while (n--) {
            long long t = pattern1;
            pattern1 = (pattern1 * 2 + pattern2 * 2) % MOD;
            pattern2 = (pattern2 * 3 + t * 2) % MOD;
        }
        
        return (pattern1 + pattern2) % MOD;
    }     
};