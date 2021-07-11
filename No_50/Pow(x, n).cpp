class Solution {
public:
    double myPow(double x, int n) {
        return n > 0 ? pow(x, abs(n)) : 1/pow(x, abs(n));
    }
    
    long double pow(double x, int abs_n) {
        if(abs_n == 1) return x;
        if(abs_n == 0) return 1;
        long double tmp = pow(x, abs_n/2);
        if(abs_n%2 == 0) {
            return tmp*tmp;
        }
        
        return x*tmp*tmp;
        
    }
};