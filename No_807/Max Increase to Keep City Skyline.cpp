class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n);
        vector<int> colMax(n);
        int ret = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[i] = max(colMax[i], grid[j][i]);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ret += min(rowMax[i], colMax[j])-grid[i][j];
            }
        }
        return ret;
    }
};