class Solution {
private:
    bool hasBoundary;
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ret = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                hasBoundary = false;
                if(grid[i][j] != 0) {
                    int s = DFS(i, j, grid);
                    if(!hasBoundary) ret += s;
                }
            }
        }
        return ret;
    }
    
    int DFS(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(grid[i][j] == 0) return 0;
        if(i == 0 || i == m-1 || j == 0 || j == n-1) hasBoundary = true;
        grid[i][j] = 0; // mark this position visited
        return 1 + DFS(i-1, j, grid) + DFS(i+1, j, grid) + DFS(i, j+1, grid) + DFS(i, j-1, grid);
        
    }
};