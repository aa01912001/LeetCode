class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int total = a + b;
        int ca = 0, cb = 0;
        string ret = "";
        for(int i=0; i<total; i++) {
            if(cb == 2 || (ca < 2 && a >= b)) {
                ret += 'a';
                ca++;
                a--;
                cb = 0;
            } else {
                ret += 'b';
                cb++;
                b--;
                ca = 0;
            }
        }
        
        
        return ret;
    }
};