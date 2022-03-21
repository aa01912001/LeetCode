class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, star = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                left++;
            } else if(s[i] == ')') {
                right++;
            } else {
                star++;
            }
            if(left + star < right) return false;
        }
        
        left = 0;
        right = 0;
        star = 0;
        
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '(') {
                left++;
            } else if(s[i] == ')') {
                right++;
            } else {
                star++;
            }
            if(right + star < left) return false;
        }
        
        return true;
    }
};