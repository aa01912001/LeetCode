class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return backString(s) == backString(t);
    }
    
    string backString(string str) {
        stack<char> s;
        for(int i=0; i<str.length(); i++) {
            if(str[i] == '#') {
                if(!s.empty()) s.pop();
            } else {
                s.push(str[i]);
            }
        }
        
        string ret = "";
        while(!s.empty()) {
            ret = s.top() + ret; s.pop();
        }
        
        cout << ret << endl;
        return ret;
    }
};