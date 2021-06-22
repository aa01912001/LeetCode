class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> count(n+1, 0);
        for(int i=0; i<n-1; i++) {
            if(++count[edges[i][0]] == n-1) return edges[i][0];
            if(++count[edges[i][1]] == n-1) return edges[i][1];
        }
        
        return -1;
    }
};