class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size(), ret = 0;
        if(size < n-1) return -1;
        
        vector<int> un(n, -1);
        for(int i=0; i<size; i++) {
            int n1 = findParent(connections[i][0], un);
            int n2 = findParent(connections[i][1], un);
            if(n1 != n2) {
                un[n1] = n2;
            }
        }
        
        for(int i=0; i<un.size(); i++) {
            if(un[i] == -1) ret++;
        }
        
        return ret-1;
    }
    
    int findParent(int n, vector<int>& un) {
        while(un[n] != -1) {
            n = un[n];
        }
        return n;
    }
};