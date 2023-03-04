class Solution {
private:
    int m, n;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        
        bool hasfresh = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] == true;
                } else if(grid[i][j] == 1) {
                    hasfresh = true;
                }
            }
        }

        if(q.empty() && !hasfresh) return 0;

        int ret = 0;
        while(!q.empty()) {
            ret++;
            int size = q.size();
            
            while(size--) {
                auto f = q.front(); q.pop();
                int i = f.first, j = f.second;
                if(grid[i][j] == 2) {
                    visited[i][j] = true;
                    if(checkValidPos(i-1, j) && grid[i-1][j] == 1 && !visited[i-1][j]) {
                        q.push({i-1, j});
                        grid[i-1][j] = 2;
                        visited[i-1][j] = true;
                    }
                    if(checkValidPos(i+1, j) && grid[i+1][j] == 1 &&  !visited[i+1][j]) {
                        q.push({i+1, j});
                        grid[i+1][j] = 2;
                        visited[i+1][j] = true;
                    }
                    if(checkValidPos(i, j-1) && grid[i][j-1] == 1 &&  !visited[i][j-1]) {
                        q.push({i, j-1});
                        grid[i][j-1] = 2;
                        visited[i][j-1] = true;
                    }
                    if(checkValidPos(i, j+1) && grid[i][j+1] == 1 &&  !visited[i][j+1]) {
                        q.push({i, j+1});
                        grid[i][j+1] = 2;
                        visited[i][j+1] = true;
                    }
                }   
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return ret - 1;
        
    }
    
    bool checkValidPos(int y, int x) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};