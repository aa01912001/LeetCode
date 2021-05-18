class Solution {
public:
    string truncateSentence(string s, int k) {
        int i;
        for(i=0; i<s.length() && k > 0; i++) {
            if(s[i] == ' ') k--;
        }
        
        if(i == s.length()) i++;
        return s.substr(0, i-1);
    }
};