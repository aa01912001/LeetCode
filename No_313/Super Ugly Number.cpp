class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        int uNumber[n];
        uNumber[0] = 1;
        int primeIndex[size];
        memset(primeIndex, 0, sizeof(primeIndex));
        
        for(int i=1; i<n; i++) { // find 2th ~ nth ugly number 
            int minNum = INT_MAX;
            for(int j=0; j<size; j++) { // find next ugly number
                minNum = min(minNum, uNumber[primeIndex[j]] * primes[j]);
            }
            for(int j=0; j<size; j++) { // update prime index
                if(minNum == uNumber[primeIndex[j]] * primes[j]) {
                    primeIndex[j]++;    
                }
            }
            uNumber[i] = minNum;
        }
        
        return uNumber[n-1];
    }
};