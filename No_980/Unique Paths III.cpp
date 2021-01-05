class Solution {
private:
    int ret = 0;
    int m, n;

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        int zeros = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++) { // find starting point
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) zeros++;
                if(grid[i][j] == 1) {
                    x = j;
                    y = i;
                }
            }
        }
    
        DFS(grid, x, y, zeros);
        return ret;
    }
    
    void DFS(vector<vector<int>> grid, int x, int y, int zeros) {        
        if(x < 0 || x == n) return; // if exceeds border
        if(y < 0 || y == m) return; // if exceeds border
        if(grid[y][x] == -2) return; // if has visited
        if(grid[y][x] == -1) {
            return; // if there obstacle
        }
        
        if(grid[y][x] == 2) { // if finds ending point
            if(zeros == -1) {
                ret++;    
            }
            return;
        }
        
        grid[y][x] = -2; // record visited point
        DFS(grid, x, y-1, zeros-1);
        DFS(grid, x, y+1, zeros-1);
        DFS(grid, x+1, y, zeros-1);
        DFS(grid, x-1, y, zeros-1);
        return;
    }
    
};