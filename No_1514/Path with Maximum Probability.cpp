class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, float>>> graph(n);
        for(int i=0; i<edges.size(); i++) { // build adjacency list
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        float ret = dijkstra(start, end, graph);
        if(ret == INT_MIN) return 0;
        
        return ret;
    }
    
    float dijkstra(int src, int dst, vector<vector<pair<int, float>>>& graph) {
        vector<float> dis(graph.size(), INT_MIN); // initialize maximum probability of each node
        dis[src] = 0;
        
        priority_queue<pair<float, int>> maxHeap; // pair: {distance, node}
        unordered_set<int> hasPop; // used for lazy deletion
        maxHeap.push({1, src});
        while(!maxHeap.empty()) {
            int v = maxHeap.top().second;
            float d = maxHeap.top().first;
            maxHeap.pop();
            if(hasPop.find(v) != hasPop.end()) { // if this node has been popped from maxHeap
                continue;
            }
            hasPop.insert(v);
            
            for(int i=0; i<graph[v].size(); i++) {
                float nv = d*graph[v][i].second;
                if(nv > dis[graph[v][i].first]) { // edge relaxation
                    maxHeap.push({nv, graph[v][i].first});
                    dis[graph[v][i].first] = nv;
                }
            }
        }
        
        return dis[dst];
    }
};