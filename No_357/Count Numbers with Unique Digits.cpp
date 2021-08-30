class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ret = 1; // includes 0
        for(int i=1; i<=n; i++) {
            int allDiff = 1;
            for(int a=0; a<i; a++) {
                allDiff *= (10-a);
            }
            
            int allDiffWithFirstZero = 1;
            for(int a=0; a<i-1; a++) {
                allDiffWithFirstZero *= (9-a);
            }
            
            ret += allDiff - allDiffWithFirstZero;
        }
        
        return ret;
    }
};