class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ret(n, INT_MAX);
        
        int pre = -1;
        for(int i=0; i<n; i++) {
            if(s[i] == c) {
                ret[i] = 0;
                pre = i;
            } else {
                if(pre == -1) continue;
                ret[i] = i - pre;
            }
        }
        
        pre = -1;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == c) {
                pre = i;
            } else {
                if(pre == -1) continue;
                ret[i] = min(ret[i], pre-i);
            }
        }
        
        return ret;
    }
};