class Solution {
public:
    int partitionString(string s) {
        int ret = 0;
        unordered_set<char> hset;
        for(int i=0; i<s.length(); i++) {
            if(hset.find(s[i]) != hset.end()) {
                hset.clear();
                ret++;
            }
            hset.insert(s[i]);
        }
        ret++;
        return ret;
    }
};