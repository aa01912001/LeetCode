class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m =  grid.size(), n = grid[0].size();
        int ret = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ret++;
                    markVisited(i, j, grid, visited);
                }
            }
        }
        
        return ret;
    }
    
    void markVisited(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (grid[row][col] == '0' || visited[row][col]) return;
        
        visited[row][col] = true;
        if (row-1 >= 0) markVisited(row-1, col, grid, visited);
        if (row+1 < grid.size()) markVisited(row+1, col, grid, visited);
        if (col-1 >= 0) markVisited(row, col-1, grid, visited);
        if (col+1 < grid[0].size()) markVisited(row, col+1, grid, visited);
        
        return;
    }
};