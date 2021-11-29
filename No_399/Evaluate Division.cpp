class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj; // adjacency list of DAG
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++) { // build adjacency list of DAG
            string src = equations[i][0];
            string dst = equations[i][1];
            adj[src].push_back({dst, values[i]});
            adj[dst].push_back({src, 1./values[i]});
        }
        
        vector<double> ret;
        unordered_set<string> visited;
        for(int i=0; i<queries.size(); i++) {
            ret.push_back(DFS(queries[i][0], queries[i][1], 1, visited));
        }
        
        return ret;
    }
    
    double DFS(string src, string dst, double pathWeight, unordered_set<string> visited) {
        if(src == dst && adj.find(dst) != adj.end()) { // if find out dst
            return pathWeight;
        } 
        
        if(visited.find(src) != visited.end()) return -1; // src has visited
        
        visited.insert(src);
        double ret = -1;
        for(int i=0; i<adj[src].size(); i++) { // DFS all adjcent nodes
            ret = max(ret, DFS(adj[src][i].first, dst, pathWeight*adj[src][i].second, visited));
        }
        
        return ret;
    }
};