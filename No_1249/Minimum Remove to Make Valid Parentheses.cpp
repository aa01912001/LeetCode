class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(stk.empty()) {
                    s[i] = '$';
                } else {
                    stk.pop();
                }
            }
        }
        
        while(!stk.empty()) {
            s[stk.top()] = '$';
            stk.pop();
        }
        
        string ret = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '$') {
                ret += s[i];
            }
        }
        
        return ret;
    }
};