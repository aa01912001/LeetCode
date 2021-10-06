class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.length(); i++) {
            if(word[i] == ch) {
                int j = 0;
                while(j < i) {
                    char t = word[j];
                    word[j] = word[i];
                    word[i] = t;
                    i--;
                    j++;
                }
                return word;
            }
        }
        
        return word;
    }
};