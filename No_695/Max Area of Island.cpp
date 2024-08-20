class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size())
            return 0;
        
        if (j < 0 || j >= grid[0].size())
            return 0;
        
        if (grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    ret = max(ret, dfs(grid, i, j));
            }
        }
        
        return ret;
    }
};