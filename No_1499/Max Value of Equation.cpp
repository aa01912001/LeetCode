class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ret = INT_MIN;
        deque<vector<int>> dq;
        for (int i = 0; i < points.size(); i++) {
            while (!dq.empty() && points[i][0] - dq.front()[0] > k)
                dq.pop_front();
            if (!dq.empty())
                ret = max(ret, points[i][0] - dq.front()[0] + points[i][1] + dq.front()[1]);
            while (!dq.empty() && points[i][1] - dq.back()[1] >= points[i][0] - dq.back()[0])
                dq.pop_back();
            dq.push_back(points[i]);
        }
        
        return ret;
    }
};