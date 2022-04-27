class Solution {
public:
    int minimumMoves(string s) {
        int ret = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'X') {
                ret++;
                i += 2;
            }
        }
        return ret;
    }
};