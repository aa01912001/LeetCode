class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> check(n);
        for(int i=0; i<edges.size(); i++) {
            check[edges[i][1]] = 1;
        }
        
        vector<int> ret;
        for(int i=0; i<n; i++) {
            if(check[i] == 0) ret.push_back(i); 
        }
        
        return ret;
    }
};