class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> hset;
        for(int i=0; i<allowed.length(); i++) {
            hset.insert(allowed[i]);
        }
        
        int ret = words.size();
        for(int i=0; i<words.size(); i++) { // traverse all vector
            int j;
            for(j=0; j<words[i].length(); j++) { // determine string
                if(hset.find(words[i][j]) == hset.end()) { // if char is invalid
                    ret--;
                    break;
                }
            }
        }
        
        return ret;
    }
};