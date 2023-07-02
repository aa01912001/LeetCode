class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> sweepPoints, ret;
        map<int, int> treeMap;
        int n = buildings.size();
        for (int i = 0; i < n; i++) {
            sweepPoints.push_back({buildings[i][0], buildings[i][2], 1});
            sweepPoints.push_back({buildings[i][1], buildings[i][2], -1});
        }
        
        sort(sweepPoints.begin(), sweepPoints.end(), [](const vector<int> &i, const vector<int> &j){
            if (i[0] == j[0]) {
                if (i[2] == j[2]) {
                    return i[1] > j[1];
                }
                return i[2] > j[2];
            }
            
            return i[0] < j[0];
        });
        
        
        for (int i = 0; i < 2 * n; i++) {
            if (sweepPoints[i][2] == 1) {
                // left edge
                if (treeMap.empty() || treeMap.rbegin()->first < sweepPoints[i][1])
                    ret.push_back({sweepPoints[i][0], sweepPoints[i][1]});
                treeMap[sweepPoints[i][1]]++;
            } else {
                // right edge
                treeMap[sweepPoints[i][1]]--;
                if (treeMap[sweepPoints[i][1]] == 0) {
                    treeMap.erase(sweepPoints[i][1]);
                }
                if (treeMap.empty()) {
                    ret.push_back({sweepPoints[i][0], 0});
                } else if (treeMap.rbegin()->first < sweepPoints[i][1]) {
                    ret.push_back({sweepPoints[i][0], treeMap.rbegin()->first});
                }
                
            }
        }
        
        vector<vector<int>> filteredResult;
        for (int i = 0; i < ret.size(); i++) {
            if (i == ret.size()-1 || ret[i][0] != ret[i+1][0]) {
                filteredResult.push_back(ret[i]);
            }
        }
        
        return filteredResult;
    }
};