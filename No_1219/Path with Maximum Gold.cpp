class Solution {
private:
    int m;
    int n;
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ret = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) {
                    ret = max(ret, getGold(i, j, grid));    
                }   
            }
        }   
        
        return ret;
    }
    
    int getGold(int i, int j, vector<vector<int>>& grid) {
        if(i<0  || j<0 || j>=n || i>=m || grid[i][j] == 0) {
            return 0;
        } 
        
        int tmp = grid[i][j];
        grid[i][j] = 0;
        
        int up = getGold(i-1, j, grid);
        int down = getGold(i+1, j, grid);
        int left = getGold(i, j-1, grid);
        int right = getGold(i, j+1, grid);
        grid[i][j] = tmp;
        
        return tmp + max(up, max(down, max(left, right)));
    }
};