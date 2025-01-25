class Solution {
public:
    void generator(vector<string> &ret, string &s, int n) {
        int strLen = s.size();
        if (strLen > 1 && s[strLen-1] == '0' && s[strLen-2] == '0') {
            return;
        }

        if (n == 0) {
            ret.push_back(s);
            return;
        }

        s += '0';
        generator(ret, s, n-1);
        s.pop_back();

        s += '1';
        generator(ret, s, n-1);
        s.pop_back();

        return;
    }

    vector<string> validStrings(int n) {
        vector<string> ret;
        string s = "";
        generator(ret, s, n);
        return ret;
    }
};