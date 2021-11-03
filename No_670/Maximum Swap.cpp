class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        string ret = numStr;
        int size = numStr.length();
        int maxVal = numStr[size-1] - '0', maxIndex = size - 1;
        for(int i=size-2; i>=0; i--) {
            int val = numStr[i] - '0';
            if(val > maxVal) {
                maxVal = val;
                maxIndex = i;
            }
            
            if(val < maxVal) {
                // swap numStr[i] and numStr[maxIndex]
                char t = numStr[i]; 
                numStr[i] = numStr[maxIndex];
                numStr[maxIndex] = t;
                
                ret = numStr;
                
                // swap numStr[i] and numStr[maxIndex]
                t = numStr[i];
                numStr[i] = numStr[maxIndex];
                numStr[maxIndex] = t;
            }
        }
        
        return stoi(ret);
        
    }
};