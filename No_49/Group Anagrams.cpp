class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret; 
        unordered_map<string, vector<string>> h; // store groups
        for(int i=0; i<strs.size(); i++) { // traverse all strings
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end()); // sort string
            if(h.find(strs[i]) == h.end()) { // if no same anagram in map
                vector<string> g = {tmp};
                h[strs[i]] = g;
            }else { // if exists a same anagram in map 
                h[strs[i]].push_back(tmp);
            }
            
        }
        
        unordered_map<string, vector<string>>::iterator it;
        for(it=h.begin(); it != h.end(); it++) { // traverse all groups in map
            ret.push_back(it->second);
        }
                
        return ret;
    }
};