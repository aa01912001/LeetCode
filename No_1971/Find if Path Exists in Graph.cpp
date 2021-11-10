class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> set(n, -1);
        for(int i=0; i<edges.size(); i++) {
            int a = find(set, edges[i][0]);
            int b = find(set, edges[i][1]);
            if(a != b) set[b] = a;
        }
        
        return find(set, start) == find(set, end);
    }
    
    int find(vector<int>& set, int num) {
        while(set[num] != -1) {
            num = set[num];
        }
        
        return num;
    }
};