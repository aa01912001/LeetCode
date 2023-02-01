class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        vector<int> preSumZero(n), preSumOne(n);
        s[0] == '0' ? preSumZero[0] = 1 : preSumOne[0] = 1;
        for(int i=1; i<n; i++) {
            preSumZero[i] += preSumZero[i-1];
            preSumOne[i] += preSumOne[i-1];
            s[i] == '0' ? preSumZero[i] += 1 : preSumOne[i] += 1;
        }

        long long ret = 0;
        for(int i=1; i<n; i++) {
            if(s[i] == '0') {
                ret += preSumOne[i-1] * (preSumOne[n-1] - preSumOne[i]);
            } else {
                ret += preSumZero[i-1] * (preSumZero[n-1] - preSumZero[i]);
            }
        }

        return ret;
    }
};