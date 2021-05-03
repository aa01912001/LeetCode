class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), bitCompare);
        
        return arr;
    }

    static bool bitCompare(int a, int b) {
        int aBit = 0;
        int bBit = 0;
        int aa = a;
        int bb = b;
        while(aa) {
            aBit++;
            aa &= (aa-1);
        }
        
        while(bb) {
            bBit++;
            bb &= (bb-1);
        }
        
        if(aBit == bBit) {
            return a < b; 
        }
        
        return aBit < bBit;
        
    }
};