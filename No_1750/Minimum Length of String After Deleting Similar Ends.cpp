class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length()-1;
        while(left < right) {
            int i = left, j = right;
            while(i < j) {
                if(s[i+1] != s[i]) break;
                i++;
            }
            
            while(j > i) {
                if(s[j-1] != s[j]) break;
                j--;
            }
            if(s[i] != s[j]) break;
            left = i + 1;
            right = j - 1;
        }
        
        if(left == right) {
            return 1;
        } else if(right < left) {
            return 0;
        }
        
        return right-left+1;
    }
};