class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0;
        for(int i=0; i<s.length(); i++) {
            flips += s[i]-'0';
        }
        
        int mn = flips;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '1') {
                flips -= 1;
            } else {
                flips += 1;
            }
            mn = min(mn, flips);
        }
        
        return mn;
    }
};