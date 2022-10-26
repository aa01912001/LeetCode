class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ret = s;
        int n = s.length();
        if(k == 1) {
            for(int i=0; i<n; i++) {
                ret = min(ret, s.substr(i) + s.substr(0, i));
            }
            return ret;
        }
      
        sort(s.begin(), s.end());
        return s;
    }
};