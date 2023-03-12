class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long ret = 0;
        long long points = 0;
        for(int i=0; i<n; i++) {
            if(visited[i] == true) continue;
            int nums = dfs(graph, visited, i);
            ret += nums * points;
            points += nums;
        }
        
        return ret;
    }
    
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int root) {
        visited[root] = true;
        int nums = 0;
        for(int i=0; i<graph[root].size(); i++) {
            if(visited[graph[root][i]] == true) continue;
            nums += dfs(graph, visited, graph[root][i]);
        }
        return nums + 1;
    }
};