#define ll long long 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, ll>>> graph(n);
        for(int i=0; i<roads.size(); i++) { // build adjacency list
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]}); // node: {node, time}
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        return Dijkstra(graph);
    }
    
    int Dijkstra(vector<vector<pair<int, ll>>>& graph) {
        int src = 0, dst = graph.size()-1;
        vector<pair<ll, ll>> dis(graph.size(), {LLONG_MAX, 0});
        dis[0] = {0, 1};
        
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap; // {time, node}
        minHeap.push({0, src});
        while(!minHeap.empty()) {
            ll w = minHeap.top().first;
            int n = minHeap.top().second;
            minHeap.pop();
            for(int i=0; i<graph[n].size(); i++) {
                if(w+graph[n][i].second < dis[graph[n][i].first].first) { // if find new path with less time
                    dis[graph[n][i].first].first = w+graph[n][i].second;
                    dis[graph[n][i].first].second = dis[n].second % 1000000007;
                    minHeap.push({dis[graph[n][i].first].first, graph[n][i].first}); // lazy deletion
                } else if(w+graph[n][i].second == dis[graph[n][i].first].first) { // if same time
                    dis[graph[n][i].first].second += dis[n].second % 1000000007;
                }
            }
        }
        
        return dis[dst].second % 1000000007;
    }
};