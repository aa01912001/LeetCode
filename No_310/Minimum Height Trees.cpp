class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0}; // trivial case
        unordered_map<int, vector<int>> graph; 
        vector<int> degree(n, 0);
        for(auto e : edges) { // build graph and degree
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1) { // push leaf nodes into queue
                q.push(i);
                degree[i]--; // remove it from graph
            }
        }
        
        vector<int> ret;
        while(!q.empty()) {
            ret.clear();
            int size = q.size();
            for(int i=0; i<size; i++) { // pop all leafs from queue
                int node = q.front(); q.pop();
                ret.push_back(node);
                for(int j=0; j<graph[node].size(); j++) { // decrease neighbor's degree
                    int neigbor = graph[node][j];
                    degree[neigbor]--;
                    if(degree[neigbor] == 1) { // choose it as new leaf
                        q.push(neigbor);
                    }
                }    
            }
        }
        return ret;
    }
};