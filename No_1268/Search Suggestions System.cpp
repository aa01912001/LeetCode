class Node {
public:
    Node* child[26];
};
class Solution {
private:
    Node trie;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        init(searchWord);
        Node* root = &trie;
        vector<vector<string>> ret(searchWord.length());
        sort(products.begin(), products.end());
        for(int i=0; i<products.size(); i++) {
            build(products[i], ret);    
        }
        
        return ret;
    }
    
    void init(string s) {
        Node* root = &trie;
        for(int i=0; i<s.length(); i++) {
            int c = s[i]-'a';
            root->child[c] = new Node();
            root = root->child[c];
        }
        return;
    }
    
    void build(string product, vector<vector<string>>& ret) {
        Node* root = &trie;
        int idx = 0;
        for(char c : product) {
            if(root->child[c-'a'] == nullptr) break;
            if(ret[idx].size() <= 2) ret[idx].push_back(product);
            root = root->child[c-'a'];
            idx++;
        }
    }
};