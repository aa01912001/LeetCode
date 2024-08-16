class UnionFind {
    vector<int> groups, heights;
    int components;
public:
    UnionFind(int n): groups(n+1), heights(n+1, 1), components(n){}
    
    int Union(int i, int j) {
        int root1 = Find(i);
        int root2 = Find(j);
       
        if (root1 == root2) return 0;
        
        if (heights[root1] < heights[root2]) {
            groups[root1] = root2;
            heights[root2] = max(heights[root2], heights[root1] + 1);
        } else {
            groups[root2] = root1;    
            heights[root1] = max(heights[root1], heights[root2] + 1);
        }
        
        components--;
        return 1;
    }
    
    int Find(int i) {
        if (groups[i] == 0)
            return i;
        
        return groups[i] = Find(groups[i]);
    }
    
    bool isConnected() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n), Bob(n);
        
        int requiredEdges = 0;
        for (auto e : edges) {
            if (e[0] == 3)
                if (Alice.Union(e[1], e[2]) and Bob.Union(e[1], e[2]))
                    requiredEdges++;
        }
        
        for (auto e: edges) {
            if (e[0] == 1)
                requiredEdges += Alice.Union(e[1], e[2]);
            else if (e[0] == 2)
                requiredEdges += Bob.Union(e[1], e[2]);
            
        }
        
        if (Alice.isConnected() && Bob.isConnected())
            return edges.size() - requiredEdges;
        
        return -1;
    }
};