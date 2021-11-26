class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != ']') {
                stk.push(s[i]);
            } else {
                string tmp = "";
                while(stk.top() != '[') { // get string bwtween '[' and ']'
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                stk.pop();
                
                string times = "";
                while(!stk.empty() && isdigit(stk.top())) { // get number before '['
                    times = stk.top() + times;
                    stk.pop();
                }
                
                string ts = "";
                for(int i=0; i<stoi(times); i++) { // number*string 
                    ts += tmp;
                }
                
                for(int i=0; i<ts.length(); i++) { // push constructed string into stack
                    stk.push(ts[i]);
                }
            }
        }
        
        string ret;
        while(!stk.empty()) { // get complete answer string from stack
            ret = stk.top() + ret;
            stk.pop();
        }
        
        return ret;
    }
};