class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxProfLeft(n), maxProfRight(n);
        int acc = 0;
        for (int i=1; i<n; i++) {
            acc += prices[i] - prices[i-1];
            if (acc > 0) {
                maxProfLeft[i] = acc;
            } else {
                acc = 0;
            }
        }

        acc = 0;
        for (int i=n-2; i>=0; i--) {
            acc += prices[i] - prices[i+1];
            if (acc < 0) {
                maxProfRight[i] = abs(acc);
            } else {
                acc = 0;
            }
        }
    
        for (int i=1; i<n; i++) {
            maxProfLeft[i] = max(maxProfLeft[i], maxProfLeft[i-1]);
        }
        
        for (int i=n-2; i>=0; i--) {
            maxProfRight[i] = max(maxProfRight[i], maxProfRight[i+1]);
        }
        
        int ret = 0;
        for (int i=1; i<n-1; i++) {
            ret = max(ret, maxProfLeft[i]+maxProfRight[i+1]);
            ret = max(ret, maxProfLeft[i-1]+maxProfRight[i]);
        }
        
        // if only one transaction and sell on last day
        ret = max(ret, maxProfLeft[n-1]);
        
        return ret;
        
    }
};