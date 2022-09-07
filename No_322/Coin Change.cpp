class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            int fewest = INT_MAX;
            for(int j=0; j<coins.size(); j++) {
                if(coins[j] > i) continue;
                if(dp[i-coins[j]] != -1)
                    fewest = min(fewest, dp[i-coins[j]]+1);
                
            }
            if(fewest != INT_MAX)
                dp[i] = fewest;
        }
        return dp[amount];
    }
};