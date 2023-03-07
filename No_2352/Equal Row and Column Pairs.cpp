class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> hmap;
        int ret = 0;
        
        for(int i=0; i<n; i++) {
            hmap[grid[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            vector<int> v(n);
            for(int j=0; j<n; j++) {
                v[j] = grid[j][i];
            }
            ret += hmap[v];
        }
        
        return ret;
    }
};