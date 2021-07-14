class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        while(a > 0 || b > 0 || c > 0) {
            int d1 = a % 2; a /= 2;
            int d2 = b % 2; b /= 2; 
            int d3 = c % 2; c /= 2;
            if(d3 == 0) {
                if(d1 || d2) {
                    ret += d1 + d2;
                }
            } else { // d3 == 1
                if(!d1 && !d2) {
                    ret += 1;
                }
            }
        }
        
        return ret;
    }
};