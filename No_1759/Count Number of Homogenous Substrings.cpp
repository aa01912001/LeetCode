class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long long ret = 1;
        int n = s.length(), left = 0, right = 1;
        
        while (right < n) {
            if (s[left] == s[right]) {
                ret = (ret + right - left + 1) % MOD;
            } else {
                ret = (ret + 1) % MOD;
                left = right;
            }
            right++;
        }
        
        return ret;
    }
};