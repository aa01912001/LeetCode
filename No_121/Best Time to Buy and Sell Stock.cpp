class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int buyPoint = prices[0];
        for(int i=1; i<prices.size(); i++) {
            ret = max(ret, prices[i]-buyPoint);
            buyPoint = min(buyPoint, prices[i]);
        }
        return ret;
    }
};