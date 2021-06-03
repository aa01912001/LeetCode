class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ret = 0;
        sort(piles.begin(), piles.end());
        for(int i = piles.size()/3; i<piles.size(); i+=2) {
            ret += piles[i];
        }
        
        return ret;
    }
};