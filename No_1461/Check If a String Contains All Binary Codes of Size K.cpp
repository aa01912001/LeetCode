class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        unordered_set<string> hset;
        for(int i=0; i<s.length()-k+1; i++) {
            hset.insert(s.substr(i, k));
        }
            
        return hset.size() == pow(2, k);
    }
};