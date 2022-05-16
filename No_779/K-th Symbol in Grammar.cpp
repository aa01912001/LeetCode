class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 || k == 1) return 0;
        int count = pow(2, n-1);
        if(k <= count/2) {
            return kthGrammar(n-1, k);
        }
        
        return !kthGrammar(n-1, k-count/2);
    }
};