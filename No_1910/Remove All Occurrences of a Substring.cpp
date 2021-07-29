class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> c, t;
        int plen = part.length();
        for(int i=0; i<s.length(); i++) {
            if(s[i] == part[plen-1]) {
                t.push(s[i]);
                for(int j=plen-2; j>=0; j--) {
                    if(!c.empty() && c.top() == part[j]) {
                        t.push(c.top()); c.pop();
                    } else {
                        while(!t.empty()) {
                            c.push(t.top()); t.pop();
                        }
                        break;
                    }
                }
                while(!t.empty()) {
                    cout << t.top() << endl;
                    t.pop();
                }
            } else {
                c.push(s[i]);
            }
        }
        
        string ret = "";
        while(!c.empty()) {
            ret = c.top() + ret; c.pop();
        }
        
        return ret;
        
    }
};