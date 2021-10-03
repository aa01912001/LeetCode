class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        split(s, words);
        
        if(pattern.length() != words.size()) return false;
        
        unordered_map<string, char> hmap;
        vector<bool> flag(26, false);
        for(int i=0; i<words.size(); i++) {
            if(hmap.find(words[i]) != hmap.end()) {
                if(pattern[i] != hmap[words[i]]) return false;
            } else {
                if(flag[pattern[i]-'a']) {
                    return false;
                }
                hmap[words[i]] = pattern[i];
                flag[pattern[i]-'a'] = true;
            }
        }
        
        return true;
    }
    
    void split(string s, vector<string>& w) {
        string t = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                w.push_back(t);
                t = "";
            } else {
                t = t + s[i];
            }
        }
        w.push_back(t);
        
        for(int i=0; i<w.size(); i++) {
            cout << w[i] << endl;
        }
        return;
    }
};