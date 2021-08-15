class Solution {
public:
    string largestOddNumber(string num) {
        string ret = "";
        
        for(int i=num.length()-1; i>=0; i--) {
            if((num[i]-'0')%2 == 1) {
                ret = num.substr(0, i+1);
                break;
            }
        }
        
        return ret;
    }
};