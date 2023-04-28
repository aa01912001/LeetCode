class Solution {
public:
    string removeStars(string s) {
        string ret = "";
        int count = 0;
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] == '*') {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    ret += s[i];
                }
            }
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};