class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0); // 0: not visited, 1: safe, 2: unsafe
        vector<int> ret;
        for(int i=0; i<graph.size(); i++) {
            if(DFS(graph, i, color)) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
    
    bool DFS(vector<vector<int>>& graph, int n, vector<int>& color) {
        if(color[n] == 1) return true;
        if(color[n] == 2) return false;
        
        color[n] = 2; // default unsafe
        for(int e : graph[n]) { // check if every path starting from n leads to a safe node
            if(!DFS(graph, e, color)) return false;
        }
        
        color[n] = 1;
        return true;
    }
};