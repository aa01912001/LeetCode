class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    if(DFS(grid, i, j)) ret++;   
                }
            }
        }
        
        return ret;
    }
    
    bool DFS(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) {
            return false;
        }
        
        if(grid[i][j] == -1 || grid[i][j] == 1) {
            return true;
        }
        
        grid[i][j] = -1;
        bool a1,a2,a3,a4;
        a1 = DFS(grid, i-1, j);
        a2 = DFS(grid, i+1, j); 
        a3 = DFS(grid, i, j-1);
        a4 = DFS(grid, i, j+1);
        return a1 && a2 && a3 && a4;
    }
};

