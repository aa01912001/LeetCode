class Solution {
public:
    long long countVowels(string word) {
        long long ret = 0;
        long long dp = 0;
        for(int i=0; i<word.length(); i++) {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                ret += dp + i + 1;
                dp += i + 1;
            } else {
                ret += dp;
            }
        }
        return ret;
    }
};