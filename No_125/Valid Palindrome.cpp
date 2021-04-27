class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> prettyString;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                prettyString.push_back(c);
            } else if(isalpha(c)) {
                prettyString.push_back(tolower(c));
            }
            
        }  
        
        int i = 0, j = prettyString.size()-1;
        while(i<j) {
            if(prettyString[i] != prettyString[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
};