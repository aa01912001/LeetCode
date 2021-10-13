class Solution {
public:
    char findKthBit(int n, int k) {
        string Sn = findSn(n);
        return Sn[k-1];
    }
    
    string findSn(int n) {
        if(n == 1) {
            return "0";   
        }
        
        string pre = findSn(n-1);
        return pre + "1" + reverse(invert(pre));
    }
    
    string invert(string pre) {
        for(int i=0; i<pre.length(); i++) {
            pre[i] == '0' ? pre[i] = '1' : pre[i] = '0';
        }
        
        return pre;
    }
    
    string reverse(string s) {
        int len = s.length();
        for(int i=0; i<len/2; i++) {
            char t = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = t;
        }
        
        return s;
    }
};