class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) { // sort lower triangular matrix
            int k = i, j = 0;
            vector<int> s;
            while(k < m && j < n) {
                s.push_back(mat[k][j]);
                k++;
                j++;
            }
            
            sort(s.begin(), s.end());
            k = i, j = 0;
            while(k < m && j < n) {
                mat[k][j] = s[j];
                k++;
                j++;
            }
        }
        
        for(int j=1; j<n; j++) { // sort strictly upper triangular matrix
            int i = 0, k = j;
            vector<int> s;
            while(i < m && k < n) {
                s.push_back(mat[i][k]);
                i++;
                k++;
            }
            
            sort(s.begin(), s.end());
            i = 0, k = j;
            while(i < m && k < n) {
                mat[i][k] = s[i];
                i++;
                k++;
            }
        }
        
        return mat;
    }
};