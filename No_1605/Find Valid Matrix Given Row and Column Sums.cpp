class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> ret(row, vector<int>(col));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                int m = min(rowSum[i], colSum[j]);
                rowSum[i] -= m;
                colSum[j] -= m;
                ret[i][j] = m;
            }
        }
        return ret;
    }
};