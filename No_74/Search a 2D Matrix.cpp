class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int i = 0, j = matrix.size() - 1;
        while(i < j) { // binary search for row
            int mid = (i + j) / 2. + 0.5;
            if(matrix[mid][0] < target) {
                i = mid;
            } else if(matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                j = mid;
                break;
            }
        }
        row = j;
        i = 0;
        j = matrix[0].size() - 1;
        while(i <= j) { // binary search for column
            int mid = (i + j) / 2;
            if(matrix[row][mid] < target) {
                i = mid + 1;
            } else if(matrix[row][mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};