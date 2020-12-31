class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int ex = 0;
        int ret = 0;
        while(N > 0) { //  check each bit of N
            if(N % 2 == 0) ret += pow(2, ex);         
            ex++;
            N /= 2;
        }
        
        return ret;
    }
};