class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0; i<connections.size(); i++) { // build adjacency  list of DAG
            graph[connections[i][0]].push_back({connections[i][1], 0}); // 0 stands for in
            graph[connections[i][1]].push_back({connections[i][0], 1}); // 1 stands for out
        }
        
        int ret = 0;
        DFS(0, -1, ret, graph);
        
        return ret;
    }
    
    void DFS(int cur, int pre, int& ret, vector<vector<pair<int, int>>>& graph) {
        for(int i=0; i<graph[cur].size(); i++) {
            if(graph[cur][i].first == pre) continue; // pass previous node
            if(graph[cur][i].second == 0) ret++; // this edge needs to be reversed
            DFS(graph[cur][i].first, cur, ret, graph); // DFS
        }
        return;
    }
};