class TreeAncestor {
private:
    vector<vector<int>> bLifting;
public:
    TreeAncestor(int n, vector<int>& parent) {
        int mostPower = log2(n) + 1;
        bLifting.assign(n, vector<int>(mostPower+1, -1));
    
        for (int i = 0; i < n; i++) {
            bLifting[i][0] = parent[i];
        }
        
        for (int j = 1; j <= mostPower; j++) {
            for (int i = 0; i < n; i++) {
                if (bLifting[i][j-1] == -1)
                    continue;
                int t = bLifting[i][j-1];
                bLifting[i][j] = bLifting[t][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        while (k > 0) {
            if (node == -1) return -1;
            int t = log2(k);
            node = bLifting[node][t];
            k -= pow(2, t);
            
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */