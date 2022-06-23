class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1) return ""; // the only case that makes palindrome impossible to break
        for(int i=0; i<n/2; i++) {
            if(palindrome[i] != 'a') { // change the first char which is not 'a' into 'a'
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b'; // if every char is 'a', change the last char into 'b'
        return palindrome;
    }
};