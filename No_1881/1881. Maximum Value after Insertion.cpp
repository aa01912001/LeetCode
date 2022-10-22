class Solution {
public:
    string maxValue(string n, int x) {
        int len = n.length();
        string ret = "";
        if(n[0] != '-') { // positive number
            for(int i=0; i<len; i++) {
                if(x > (n[i]-'0')) {
                    ret = n.substr(0, i) + to_string(x) + n.substr(i, len-i);
                    break;
                }
            }
            if(ret == "") { // x is the smallest digit in n
                ret = n + to_string(x);
            }
        } else { // negative number
            for(int i=0; i<len; i++) {
                if(x < (n[i]-'0')) {
                    ret = n.substr(0, i) + to_string(x) + n.substr(i, len-i);
                    break;
                }
            }
            if(ret == "") { // x is the biggest digit in n
                ret = n + to_string(x);
            }
        }
        
        return ret;
    }
};