class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ret = 0;
        int tmp = cost[0];
        int all = cost[0];
        int p = 0, q = 1;
        for(; q<s.length(); q++) {
            if(s[q] == s[q-1]) { // if consecutive same char
                tmp = max(tmp, cost[q]);
                all += cost[q];
            } else {
                if(q-p != 1) { // if there are consecutive same chars between s[p] ~ s[q]
                    ret += all-tmp;
                }
                tmp = cost[q];
                p = q;
                all = cost[q];
            }
        }
        
        if(q - p > 1) {
            ret += all-tmp;
        }
        
        return ret;
    }
};