class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> weight(n+1, INT_MAX);
        weight[k] = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<times.size(); j++) {
                if(weight[times[j][0]] != INT_MAX && weight[times[j][0]] + times[j][2] < weight[times[j][1]]) {
                    weight[times[j][1]] = weight[times[j][0]] + times[j][2];
                }
            }
        }
        
        int ret = 0;
        for(int i=1; i<=n; i++) {
            if(weight[i] == INT_MAX) return -1;
            ret = max(ret, weight[i]);
        }
        
        return ret;
    }
};