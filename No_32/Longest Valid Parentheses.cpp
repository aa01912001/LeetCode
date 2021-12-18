class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        
        int ret = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else {
                if(stk.size() == 1) {
                    stk.pop();
                    stk.push(i);
                } else {
                    stk.pop();
                    ret = max(ret, i-stk.top());
                }
            }
        }
        
        return ret;
    }
};