class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        for(int i=0; i<31; i++) {
            string powerStr = to_string(1 << i);
            sort(powerStr.begin(), powerStr.end());
            if(powerStr == str) return true;
        }
        return false;
    }
};