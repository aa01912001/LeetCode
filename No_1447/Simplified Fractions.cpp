class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        for(int denominator = 2; denominator <= n; denominator++) {
            for(int numerator = 1; numerator < denominator; numerator++) {
                if(GCD(denominator, numerator) == 1) {
                    ret.push_back(to_string(numerator)+'/'+to_string(denominator));
                }
            }
        }
        return ret;
    }
    
    int GCD(int a, int b) {
        if(a % b == 0) 
            return b;
        return GCD(b, a%b);
    }
};