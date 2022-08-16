class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negativeCount = 0;
        int minAbs = INT_MAX;
        long long positiveSum = 0;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int element = matrix[i][j];
                if(element < 0) {
                    negativeCount++;
                }
                if(abs(element) < minAbs) {
                    minAbs = abs(element);
                }
                positiveSum += abs(element);
            }
        }
        
        if(negativeCount % 2 == 0) return positiveSum;
        return positiveSum - 2*minAbs;
    }
};