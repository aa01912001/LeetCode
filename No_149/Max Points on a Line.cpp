class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 1;
        
        for(int i=0; i<n; i++) {
            unordered_map<float, int> hmap;
            for(int j=i; j<n; j++) {
                if(i == j) continue;
                float yDiff = points[i][1] - points[j][1];
                float xDiff = points[i][0] - points[j][0];
                float slope;
                if(xDiff == 0) {
                    slope = INT_MAX;
                } else {
                    slope = yDiff / xDiff;    
                }
                hmap[slope]++;
                ret = max(ret, hmap[slope]+1);
            }
        }
        
        return ret;
    }
};