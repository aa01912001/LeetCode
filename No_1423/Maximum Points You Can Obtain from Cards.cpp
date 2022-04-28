class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i=1; i<n; i++) {
            cardPoints[i] += cardPoints[i-1];
        }
    
        int ret = 0;
        int i = 0;
        while(i <= k) {
            int l = i == 0 ? 0 : cardPoints[i-1];
            int r;
            if(i == 0 && k == n) {
                r = cardPoints[n-1];
            } else {
                 r = i == k ? 0 : cardPoints[n-1] - cardPoints[n-k+i-1];
            }
            ret = max(ret, l+r);
            i++;
        }
        
        return ret;
    }
};