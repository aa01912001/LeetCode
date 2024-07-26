class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dis(n, vector<long long>(n, INT_MAX));
        
        for (auto edge : edges) {
            dis[edge[0]][edge[1]] = edge[2];
            dis[edge[1]][edge[0]] = edge[2];
        }
        
        for (int i = 0; i < n; i++)
            dis[i][i] = 0;
        
        
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        
        int ret = -1, minNumOfCities = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            int total = 0;
            for (int d : dis[i]) {
                if (d <= distanceThreshold)
                    total++;
            }
            
            if (total < minNumOfCities) {
                ret = i;
                minNumOfCities = total;
            }
        }
        
        return ret;
    }
};