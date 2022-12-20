class Solution {
private:
    int rowNum, colNum;
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        rowNum = grid.size();
        colNum = grid[0].size();
        vector<int> ret(colNum);
        for(int i=0; i<colNum; i++) {
            ret[i] = DFS(0, i, grid);
        }
        return ret;
    }

    int DFS(int i, int j, vector<vector<int>>& grid) {
        if(grid[i][j] == 1) {
            if(j+1 == colNum || grid[i][j+1] == -1)
                return -1;
        }

        if(grid[i][j] == -1) {
            if(j-1 == -1 || grid[i][j-1] == 1) 
                return -1;
        }

        if(i == rowNum-1) {
            if(grid[i][j] == 1) {
                return j + 1;
            } else {
                return j - 1;
            }
        }

        return grid[i][j] == 1 ? DFS(i+1, j+1, grid) : DFS(i+1, j-1, grid);
    }
};