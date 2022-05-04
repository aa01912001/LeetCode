class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'c') {
                if(!stk.empty() && stk.top() == 'b') {
                    char tmp = stk.top(); stk.pop();
                    if(!stk.empty() && stk.top() == 'a') {
                        stk.pop();
                    } else {
                        stk.push(tmp);
                        stk.push(s[i]);
                    }
                } else {
                    stk.push(s[i]);
                }
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};