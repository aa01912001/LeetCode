class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '[') {
                stk.push(s[i]);
            } else {
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    stk.push(s[i]);
                }
            }
        }
        return stk.size() / 2 / 2. + 0.5;
    }
};