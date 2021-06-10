class Solution {
public:
    string makeGood(string s) {
        stack<char> S;
        for(int i=s.length()-1; i>=0; i--) {
            if(S.empty()) {
                S.push(s[i]);
            } else if(S.top()+32 == s[i] || s[i]+32 == S.top()) {
                S.pop();
            } else {
                S.push(s[i]);    
            }
            
        }
        
        string ret;
        while(!S.empty()) {
            ret += S.top();
            S.pop();
        }
        
        return ret;
    }
};