class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        timePoints.push_back(timePoints[0]);
        
        int n = timePoints.size();
        int ret = INT_MAX;
        for (int i=1; i<timePoints.size(); i++) {
            int h1 = stoi(timePoints[i].substr(0, 2)), h2 = stoi(timePoints[i-1].substr(0, 2));
            int m1 = stoi(timePoints[i].substr(3)), m2 = stoi(timePoints[i-1].substr(3));
            int diff = abs((h1 * 60 + m1) - (h2 * 60 + m2));
            ret = min(ret, min(1440-diff, diff));
        }
            
        return ret;
    }
};