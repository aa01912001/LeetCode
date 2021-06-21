class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        for(int i=0; i<queries.size(); i++) {
            ret.push_back(isMatch(queries[i], pattern));    
        }
        
        return ret;
    }
    
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        while(i != s.length()) {
            if(j != p.length() && s[i] == p[j]) {
                j++;
            } else {
                if(isupper(s[i])) return false;
            }
            i++;
        }
        
        if(j == p.length()) return true;
        return false;
    }
};