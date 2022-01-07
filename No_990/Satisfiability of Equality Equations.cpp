class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> DSU(26, -1);
        for(int i=0; i<equations.size(); i++) {
            if(equations[i][1] == '=') {
                int r1 = find(equations[i][0]-'a', DSU);
                int r2 = find(equations[i][3]-'a', DSU);
                if(r1 != r2) DSU[r2] = r1; // if not in same set
            }
        }
        
        for(int i=0; i<equations.size(); i++) {
            if(equations[i][1] == '!') {
                int r1 = find(equations[i][0]-'a', DSU);
                int r2 = find(equations[i][3]-'a', DSU);
                if(r1 == r2) return false; // if in same set
            }
        }
        
        return true;
    }
    
    int find(int v, vector<int>& DSU) {
        while(DSU[v] != -1) {
            v = DSU[v];
        }
        return v;
    }
};