class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> countForWord1(26), countForWord2(26);
        for (int i = 0; i < word1.size(); i++) {
            countForWord1[word1[i]-'a']++;
        }
        
        for (int i = 0; i < word2.size(); i++) {
            countForWord2[word2[i]-'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if ((countForWord1[i] && !countForWord2[i]) || (!countForWord1[i] && countForWord2[i]))
                return false;
        }
        
        sort(countForWord1.begin(), countForWord1.end());
        sort(countForWord2.begin(), countForWord2.end());
        
        for (int i = 0; i < 26; i++) {
            if (countForWord1[i] != countForWord2[i])
                return false;
        }
        
        return true;
    }
};