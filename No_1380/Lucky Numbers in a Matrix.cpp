class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> hmap;
        for(int i=0; i<m; i++) {
            int tmp = 100001;
            for(int j=0; j<n; j++) {
                tmp = min(tmp, matrix[i][j]);
            }
            hmap[tmp]++;
        }
        
        for(int i=0; i<n; i++) {
            int tmp = 0;
            for(int j=0; j<m; j++) {
                tmp = max(tmp, matrix[j][i]);
            }
            hmap[tmp]++;
        }
        
        vector<int> ret;
        for(auto t : hmap) {
            if(t.second == 2) ret.push_back(t.first);
        }
        
        return ret;
    }
};