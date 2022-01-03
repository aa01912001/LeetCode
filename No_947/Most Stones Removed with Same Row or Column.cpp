class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> disjointSet(n, -1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                unionStones(i, j, stones[i][0], stones[j][0], disjointSet);
                unionStones(i, j, stones[i][1], stones[j][1], disjointSet);
            }
        }
        
        int count = 0;
        for(int i=0; i<n; i++) {
            if(disjointSet[i] == -1) count++;
        }
        
        return n-count;
    }
    
    void unionStones(int i, int j, int iValue, int jValue, vector<int>& disjointSet) {
        if(iValue == jValue) {
            int pi = findParent(i, disjointSet);
            int pj = findParent(j, disjointSet);
            if(pi < pj) {
                disjointSet[pj] = pi;
            } else if(pi > pj) {
                disjointSet[pi] = pj;   
            }
        }
    }
    
    int findParent(int s, vector<int>& disjointSet) {
        int tmp = s;
        while(disjointSet[tmp] != -1) {
            tmp = disjointSet[tmp];
        }
        
        return tmp;
    }
};