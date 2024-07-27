class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int numOfVertex = 26;
        vector<vector<int>> dis(numOfVertex, vector<int>(numOfVertex, INT_MAX));
        auto x = [] (char c) {
            return c - 'a';
        };
        
        for (int i = 0; i < original.size(); i++)
            if (dis[x(original[i])][x(changed[i])] > cost[i])
                dis[x(original[i])][x(changed[i])] = cost[i];
        
        for (int i = 0; i < numOfVertex; i++)
            dis[i][i] = 0;
        
        for (int k = 0; k < numOfVertex; k++) {
            for (int i = 0; i < numOfVertex; i++) {
                for (int j = 0; j < numOfVertex; j++) {
                     if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        long long ret = 0;
        for (int i = 0; i < source.length(); i++) {
            if (dis[x(source[i])][x(target[i])] == INT_MAX)
                return -1;
            ret += dis[x(source[i])][x(target[i])];
        }
        
        return ret;
    }
};