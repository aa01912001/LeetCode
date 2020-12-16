class Solution { 
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        findPath(ret, graph, 0, {});
        return ret;
    }
    
    void findPath(vector<vector<int>>& ret, vector<vector<int>>& graph, int src, vector<int> sol) {
        sol.push_back(src);
        if(src == graph.size()-1) {
            ret.push_back(sol);
            return;
        }
        
        for(int i=0; i<graph[src].size(); i++) { // search all possible paths
            findPath(ret, graph, graph[src][i], sol);
            
        }
        
        return;
    }
};