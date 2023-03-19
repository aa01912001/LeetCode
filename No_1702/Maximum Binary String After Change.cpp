class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.length();
        string ret = "";
        
        int index = 0;
        while(binary[index] == '1') {
            ret += '1';
            index++;
        }
        
        int oneCount = 0;
        int zeroCount = 0;
        while(index < len) {
            if(binary[index] == '1') 
                oneCount++;
            else 
                zeroCount++;
            ret += '1';
            index++;
        }
        
        if(zeroCount > 0) ret[len-oneCount-1] = '0';
        return ret;
    }
};