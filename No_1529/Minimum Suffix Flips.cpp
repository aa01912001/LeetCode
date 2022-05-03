class Solution {
public:
    int minFlips(string target) {
        int len = target.length();
        char symbol = target[len-1];
        int ret = 0;
        int i = len - 2;
        while(i >= 0) {
            while(i >= 0 && symbol == target[i]) {
                i--;
            }
            if(i < 0) break;
            symbol = target[i];
            ret += 1;
        }
        
        if(symbol == '1') ret += 1;
        
        return ret;
    }
};