class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, -1); //  -1: uncolored, 0: red, 1: black
        vector<vector<int>> graph(n+1); // adjacency list
        for(int i=0; i<dislikes.size(); i++) { // build adjacency list
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1; i<=n; i++) {
            if(color[i] == -1) { // if new component
                if(coloring(i, 1, graph, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool coloring(int t, int c, vector<vector<int>>& graph, vector<int>& color) { // check if this graph can be two-coloring
        if(color[t] != -1) {
            if(c != color[t]) return true;
            return false;
        }
        
        color[t] = c;
        for(int i=0; i<graph[t].size(); i++) { // DFS
            if(coloring(graph[t][i], abs(c-1), graph, color)) {
                return true;
            }
        }
        
        return false;
    }
};