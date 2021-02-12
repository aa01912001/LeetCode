class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        int rowSize = grid[0].size();
        for(int i=0; i<grid.size(); i++) {
            int left = 0;
            int right = rowSize;
            while(left<right) { // binary search for each row
                if(grid[i][(left+right)/2] >= 0) {
                    left = (left+right)/2 + 1;
                } else {
                    right = (left+right)/2;
                }
            }
            ret += rowSize - right;
        }
        
        return ret;
    }
};