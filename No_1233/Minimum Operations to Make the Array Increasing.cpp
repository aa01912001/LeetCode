class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), []
            (const string& first, const string& second){
                return first.size() < second.size();
            });
        
        unordered_set<string> s;
        for(int i=0; i<folder.size(); i++) {
            int l, r;
            for(l=0, r=2; r<folder[i].length(); r++) { // check every validity of sub-folder in folder[i]
                if(folder[i][r] == '/') {
                    string subStr = folder[i].substr(0, r); 
                    if(s.find(subStr) != s.end()) { // if folder[i] belongs to some folder
                        break;
                    }
                }
            }
            string subStr = folder[i].substr(0, r);

            if(r == folder[i].length() && s.find(subStr) == s.end()) { // if this is a new folder
                s.insert(subStr);
            } 
        }
        
        vector<string> ret;
        for(string str : s) {
            ret.push_back(str);
        }
        
        return ret;
    }
};