class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int preMax = values[0];
        int ret = INT_MIN;
        for(int i=1; i<values.size(); i++) {
            preMax -= 1;
            ret = max(ret, values[i]+preMax);
            preMax = max(preMax, values[i]);
        }
        
        return ret;
    }
};