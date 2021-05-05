class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 11) return {};
        
        vector<string> ret;
        unordered_map<string, int> hmap;
        
        for(int i=0; i<=s.length()-10; i++) {
            string subSeq = s.substr(i, 10);
            hmap[subSeq]++;
        }
        
        for(auto &t : hmap) {
            if(t.second > 1) {
                ret.push_back(t.first);
            }
        }
        
        return ret;
    }
};