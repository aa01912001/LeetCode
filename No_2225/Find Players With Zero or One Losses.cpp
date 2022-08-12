class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ret(2);
        map<int, int> hmap;
        
        for(auto match : matches) {
            hmap[match[1]] -= 1;
            hmap[match[0]] -= 0;
        }
        
        for(auto player : hmap) {
            if(player.second == 0) ret[0].push_back(player.first);
            if(player.second == -1) ret[1].push_back(player.first);
        }
        
        return ret;
    }
};