class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++) {
            string curString = tokens[i];
            if(curString != "+" && curString != "-" && curString != "*" && curString != "/") {
                s.push(stoi(curString));
            } else {
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                if(curString == "+") s.push(op1+op2);
                if(curString == "-") s.push(op2-op1);
                if(curString == "*") s.push(op1*op2);
                if(curString == "/") s.push(op2/op1);
            }
        }
        return s.top();
    }
};