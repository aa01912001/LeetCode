class Solution {
private:
    int m;
    int n;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        int ret = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 0) continue;
                if(DFS(grid2, grid1,i, j)) {
                    ret++;
                }
            }
        }
        return ret;
    }
    
    bool DFS(vector<vector<int>> &grid2, vector<vector<int>> &grid1, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return true; // exceed edge
        if(grid2[i][j] == 0) return true; // ignore water
        grid2[i][j] = 0;
        bool up = DFS(grid2, grid1, i-1, j);
        bool down = DFS(grid2, grid1, i+1, j);
        bool left = DFS(grid2, grid1, i, j-1);
        bool right = DFS(grid2, grid1, i, j+1);
        return up && down && left && right && grid1[i][j] == 1;
    }
};