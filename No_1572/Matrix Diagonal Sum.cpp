class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len = mat.size();
        int ret = 0;
        for(int i=0; i<len; i++) {
            ret += (mat[i][i]+mat[i][len-i-1]);
        }
        
        return len%2 == 1 ? ret - mat[len/2][len/2] : ret;
    }
};