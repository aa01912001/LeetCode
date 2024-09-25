class Trie {
    int count = 0;
    Trie* next[26] = {};

public:
    void insert(string& s) {
        Trie* cur = this;
        for (char c : s) {
            int i = c - 'a';
            if (cur->next[i] == nullptr)
                cur->next[i] = new Trie();
            cur = cur->next[i];
            cur->count++;
        }
    }
    
    int countScores(string& s) {
        int total = 0;
        Trie* cur = this;
        for (char c : s) {
            cur = cur->next[c-'a'];
            total += cur->count;
        }
        
        return total;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t = Trie();
        for (string& s : words)
            t.insert(s);
        
        vector<int> ret;
        for (string& s : words)
            ret.push_back(t.countScores(s));
        
        return ret;
    }
};