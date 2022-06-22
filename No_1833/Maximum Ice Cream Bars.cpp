class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ret = 0;
        for(int i=0; i<costs.size(); i++) {
            if(costs[i] > coins) break;
            ret++;
            coins -= costs[i];
        }
        return ret;
    }
};