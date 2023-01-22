class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> visited(n);
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int result = DFS(graph, hasApple, visited, 0);
        if(result != 0) {
            return result - 2;
        }
        return 0;
    }

    int DFS(unordered_map<int, vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited, int root) {
        if(graph[root].size() == 1 && root != 0) {
            visited[root] = true;
            return hasApple[root] == true ? 2 : 0;
        }

        visited[root] = true;
        int subTreeTime = 0;
        for(int i=0; i<graph[root].size(); i++) {
            if(visited[graph[root][i]] != true) {
                subTreeTime += DFS(graph, hasApple, visited, graph[root][i]);
            }
        }

        return  (hasApple[root] == true || subTreeTime != 0) ? subTreeTime + 2 : 0;
    }
};