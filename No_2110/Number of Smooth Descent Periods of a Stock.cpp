class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<long long> dp(prices.size());
        dp[0] = 1;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]+1 == prices[i-1]) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = 1;
            }
        }

        return accumulate(dp.begin(), dp.end(), 0LL);       
    }
};