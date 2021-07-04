class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length()-1;
        while(i < j) {
            while(i != s.length()) {
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) break;
                i++;
            }
            
            while(j != -1) {
                if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) break;
                j--;
            }
            
            if(i == s.length() || j == -1 || i >= j) break;
            char t = s[j];
            s[j] = s[i];
            s[i] = t;
            i++;
            j--;
        }
        
        return s;
    }
};