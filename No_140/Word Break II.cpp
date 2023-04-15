class Solution {
private:
    unordered_map<string, vector<string>> hmap;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (hmap.count(s) != 0) return hmap[s];
        if (s.length() == 0) return {""};
        
        vector<string> ret;
        for (string word : wordDict) {
            if (s.substr(0, word.length()) != word) continue;
            vector<string> remaining = wordBreak(s.substr(word.length()), wordDict);
            for (string rmWord : remaining) {
                ret.push_back(word + (rmWord == "" ? "" : " ") + rmWord);
            }
        }
        
        return hmap[s] = ret;
    }
};