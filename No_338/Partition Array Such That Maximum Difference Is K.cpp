class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for(int i=1; i<=n; i++) {
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};