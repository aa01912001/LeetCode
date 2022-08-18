class Solution {
private:
    int m, n;
    vector<vector<int>> mem; // for memorization
    int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int ret = 1;
        mem.resize(m, vector<int>(n, 0));
    
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ret = max(ret, backtracking(matrix, i, j));
            }
        }
        return ret;
    }
    
    int backtracking(vector<vector<int>> &matrix, int row, int col) {
        if(mem[row][col] != 0) return mem[row][col];
        int len = 1;
        for(int i=0; i<4; i++) { 
            // determine 4 directions
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[row][col]) { 
                len = max(len, 1+backtracking(matrix, x, y));
            }
        }
        return mem[row][col] = len;
    }
};