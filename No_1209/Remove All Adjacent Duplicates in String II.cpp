class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char , int>> stk;
        for(int i=0; i<s.length(); i++) {
            if(stk.empty() || stk.top().first != s[i]) { 
                stk.push(make_pair(s[i], 1));
            } else {
                stk.top().second++;
                if(stk.top().second == k) { // if there are k consecutive char
                    stk.pop();
                }
            }
        }
        
        string ret = "";
        while(!stk.empty()) {
            for(int i=1; i<=stk.top().second; i++) {
                ret += stk.top().first;    
            }
            
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};