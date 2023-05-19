class TrieNode {
public:
    bool w;
    TrieNode* children[26];
};

class WordDictionary {
private:
    TrieNode* root;
    bool helper(string word, TrieNode* node) {
        if (node == nullptr) return false;
        for (int i=0; i<word.length(); i++) {
            if (word[i] != '.') {
                if (node->children[word[i] - 'a'] == nullptr)
                    return false;
                else
                    node = node->children[word[i] -'a'];
            } else {
                bool ret = false;
                for (int j=0; j<26; j++) {
                    ret |= helper(word.substr(i+1), node->children[j]);
                }
                return ret;
            }
        }
        return node->w;
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->w = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return helper(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */