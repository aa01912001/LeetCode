class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        stk.push(-1); // "-1" stands for '('
        for(int i=1; i<S.length(); i++) {
            if(S[i] == '(') { 
                stk.push(-1); 
            } else { // S[i] == ')'
                if(stk.top() == -1) { // top is '('
                    stk.pop();
                    stk.push(1);
                } else { // top is number
                    int tmp = stk.top();
                    stk.pop();
                    while(!stk.empty() && stk.top() != -1) { // solve AB rule in stack
                        tmp += stk.top();
                        stk.pop();
                    }
                    
                    tmp *= 2;
                    stk.pop(); // pop '('
                    stk.push(tmp);
                }
            }
            
            
        }
        
        int ret = 0;
        while(!stk.empty()) { // if there are still numbers in stack 
            cout << stk.top() << endl; 
            ret += stk.top();
            stk.pop();
        }
        
        return ret;
    }
};