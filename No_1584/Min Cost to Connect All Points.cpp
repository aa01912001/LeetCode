class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int n = points.size();
        for(int i=0; i<n; i++) { // insert each edge into min heap
            for(int j=i+1; j<n; j++) {
                int val = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                minHeap.push({val, i, j});
            }
        }
        return kruscal(points, minHeap);
    }
    
    int kruscal(vector<vector<int>>& points, priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>& minHeap) {
        int n = points.size();
        int ret = 0;
        vector<int> parent(n);
        for(int i=0; i<n; i++) { // initialize disjoint sets
            parent[i] = -1;
        }
        for(int i=0; i<n-1; i++) { // to find the V-1 edges of MST
            while(1) {
                int c = minHeap.top()[0];
                int e1 = minHeap.top()[1];
                int e2 = minHeap.top()[2];
                minHeap.pop();
                int p1 = findParent(e1, parent);
                int p2 = findParent(e2, parent);
                if(p1 == p2) { // cycle
                    continue;
                } else {
                    ret += c;
                    join(p1, p2, parent);
                    break;
                }
            }
        }
        return ret;
    }
    
    int findParent(int e, vector<int>& parent) {
        int p = e;
        while(parent[p] != -1) {
            p = parent[p];
        }
        return p;
    }
    
    void join(int p1, int p2, vector<int>& parent) {
        parent[p1] = p2;
        return;
    }
};