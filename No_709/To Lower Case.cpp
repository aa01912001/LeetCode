class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i<str.length(); i++) {
            if(str[i] <= 'Z' && str[i] >= 'A') {
                if(str[i] < 'a') str[i] = str[i] + ('a' - 'A');    
            }
            
        }
        return str;
    }
};