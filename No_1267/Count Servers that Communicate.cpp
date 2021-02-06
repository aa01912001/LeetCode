class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int csize = grid[0].size();
        int row[rsize];
        int col[csize];
        int sum = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i=0; i<rsize; i++) { // count the number of computer in each row
            for(int j=0; j<csize; j++) {
                row[i] += grid[i][j];
            }
            sum += row[i];
        }
        
        for(int i=0; i<csize; i++) { // count the number of computer in each column
            for(int j=0; j<rsize; j++) {
                col[i] += grid[j][i];
            }
            sum += col[i];
        }
        
        for(int i=0; i<rsize; i++) { // count isolated computer
            for(int j=0; j<csize; j++) {
                if(grid[i][j] == 1 && row[i] == 1 && col[j] == 1) sum -= 2;
            }
        }
        
        return sum/2;
    }
};