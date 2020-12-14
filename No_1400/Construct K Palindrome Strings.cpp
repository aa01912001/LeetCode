class Solution {
public:
    bool canConstruct(string s, int k) {
        int count[26] = {0};
        for(int i=0; i<s.length(); i++) { // count the number of each char in s
            count[s[i]-'a']++;
        }
        
        int odd = 0;
        for(int i=0; i<26; i++) { // count the minimum number of palindrome strings that s can generate.
            odd  += count[i] % 2;
        }
            
        return k >= odd && k <= s.length();
    }
};