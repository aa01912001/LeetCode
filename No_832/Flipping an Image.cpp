class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {  
        int size = (A[0].size()+1)/2;
        for(int i=0; i<A.size(); i++) {
            for(int j=0; j<size; j++) {
                int tmp = A[i][j];
                A[i][j] = 1^A[i][A[0].size()-1 - j];
                A[i][A[0].size()-1 - j] = 1^tmp;
            }
        }
        return A;
    }
};