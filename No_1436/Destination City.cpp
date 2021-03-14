class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hmap;
        for(int i=0; i<paths.size(); i++) {
            hmap[paths[i][1]] = 0; // default destination
        }
        
        for(int i=0; i<paths.size(); i++) {
            hmap[paths[i][0]] = -1; // not destination
        }
        
        for(unordered_map<string, int>::iterator iter = hmap.begin(); iter != hmap.end(); iter++) {
            if(iter->second == 0) return iter->first;
        }
        
        return "";
    }
};