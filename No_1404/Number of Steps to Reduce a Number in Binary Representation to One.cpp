class Solution {
public:
    int numSteps(string s) {
        int ret = 0;
        int cnt = 0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '0') {
                ret += cnt + 1;
                if(cnt != 0) { // if never met '1'
                    cnt = 1;    
                }
            } else {
                cnt++;
            }
        }
        
        if(cnt > 1) {
            ret += cnt + 1;
        }
        
        return ret;
    }
};