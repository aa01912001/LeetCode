class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> bitCount1(32), bitCount2(32);
        for(int i=0; i<arr1.size(); i++) {
            int n = arr1[i];
            int j=0;
            while(n > 0) {
                if(n%2) bitCount1[j]++;
                n >>= 1;
                j++;
            }
        }
        
        for(int i=0; i<arr2.size(); i++) {
            int n = arr2[i];
            int j=0;
            while(n > 0) {
                if(n%2) bitCount2[j]++;
                n >>= 1;
                j++;
            }
        }
        
        int ret = 0;
        for(int i=0; i<32; i++) {
            if((bitCount1[i] % 2)*(bitCount2[i] % 2) == 1) ret += 1 << i ;
        }
        
        return ret;
    }
};