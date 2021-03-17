class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for(int i=0; i<t.length(); i++) {
            ret ^= t[i]^s[i];
        }
        
        return ret;
    }
};