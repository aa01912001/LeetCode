class Solution {
public:
    bool checkPowersOfThree(int n) {
        return recursive(n, log(n)/log(3));;
    }
    
    bool recursive(int n, int x) {
        if(pow(3, x) == n) return true;
        if(x == 0 && n != 1) return false;
        if(pow(3, x) > n) return recursive(n, x-1);
        
        return recursive(n-pow(3, x), x-1);
        
    }
};