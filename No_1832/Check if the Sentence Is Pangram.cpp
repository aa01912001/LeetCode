class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> hset;
        for(int i=0; i<sentence.length(); i++) {
            hset.insert(sentence[i]);
        }
        
        return hset.size() == 26 ? true : false;
    }
};