class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int c = m + n - 1;
        vector<int> ret;
        
        for(int i=0; i<c; i++) {
            int x1, x2; // first location of each diagonal
            if(i%2 == 0) {
                x1 = min(m-1, i);
                x2 = i - x1;
            } else {
                x2 = min(n-1, i);
                x1 = i - x2;
            }
             
            while(x1 >= 0 && x1 < m && x2 >= 0 && x2 < n) {
                ret.push_back(mat[x1][x2]);
                if(i%2 == 0) {
                    x1--;
                    x2++;
                } else {
                    x2--;
                    x1++;
                }
            }
        }
        
        return ret;
    }
};