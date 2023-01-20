class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dpLeft(m, vector<int>(n));
        vector<vector<int>> dpUp(m, vector<int>(n));
        int ret = grid[0][0];

        dpLeft[0][0] = grid[0][0];
        dpUp[0][0] = grid[0][0];

        for(int i=1; i<m; i++) {
            if(grid[i][0] == 1) {
                dpUp[i][0] = dpUp[i-1][0] + 1;
                dpLeft[i][0] = 1;
                ret = 1;
            }
        }

        for(int i=1; i<n; i++) {
            if(grid[0][i] == 1) {
                dpLeft[0][i] = dpLeft[0][i-1] + 1;
                dpUp[0][i] = 1;
                ret = 1; 
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(grid[i][j] == 1) {
                    int minLen = min(dpLeft[i][j-1], dpUp[i-1][j]);
                    dpLeft[i][j] = dpLeft[i][j-1] + 1;
                    dpUp[i][j] = dpUp[i-1][j] + 1;
                    if(minLen == 0) {
                        ret = max(ret, 1);
                        continue;
                    }
                    for(int k=1; k<=minLen; k++) {
                        if(min(dpUp[i][j-k], dpLeft[i-k][j]) >= k+1) {
                            ret = max(ret, (k+1)*(k+1));
                        }
                    }
                    ret = max(ret, 1);
                }
            }
        }

        return ret;
    }
};