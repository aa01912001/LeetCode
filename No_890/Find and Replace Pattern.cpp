class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(int i=0; i<words.size(); i++) { // traverse all words
            vector<char> map(26, '-'); // store the mapping from word to pattern
            vector<char> imap(26, '-'); // store the mapping from pattern word
            int j;
            for(j=0; j<pattern.length(); j++) { // traverse each char in pattern
                if(map[words[i][j] - 'a'] == '-') { // if the char in word has not been mapped yet.
                    if(imap[pattern[j]-'a'] != '-' && imap[pattern[j]-'a'] != words[i][j]) break; // to ensure the mapping between word and pattern is 1-1.
                    map[words[i][j] - 'a'] = pattern[j];
                    imap[pattern[j]-'a'] = words[i][j];
                }else {
                    if(map[words[i][j] - 'a'] != pattern[j]) break; // encounter the event that another char has to map to the char which has been used.
                }
            }
            
            if(j == pattern.length()) { // if all char in word can map to pattern successfully.
                ret.push_back(words[i]);
            }
        }
        
        return ret;
    }
};