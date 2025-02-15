class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, 1);
        int ret = 0;

        for (int col = 1; col < n; col++) {
            vector<int> new_dp(m, 0);
            for (int row = 0; row < m; row++) {
                int num = grid[row][col];
                if (row - 1 >= 0 && num > grid[row-1][col-1] && dp[row-1])
                    new_dp[row] = 1;
                if (num > grid[row][col-1] && dp[row])
                    new_dp[row] = 1;
                if (row + 1 < m && num > grid[row+1][col-1] && dp[row+1])
                    new_dp[row] = 1;
            }
            dp = new_dp;
            if (*max_element(dp.begin(), dp.end()) == 0)
                break;
            ret += 1;
        }

        return ret;
    }
};