class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int outDegree[N+1];
        memset(outDegree, 0, sizeof(outDegree));
        for(int i=0; i<trust.size(); i++) { // calculate the out-degree from i to N
            outDegree[trust[i][0]]++;
        }
        
        int judge = 0;
        for(int i=1; i<=N; i++) { // find the label of judge
            if(outDegree[i] == 0) judge = i;
        }
        
        if(judge == 0) return -1; // if no judge
        
        int toJudge[N+1]; 
        memset(toJudge, 0, sizeof(toJudge));
        for(int i=0; i<trust.size(); i++) { // record whether every person trusts judge
            if(trust[i][1] == judge) toJudge[trust[i][0]] = 1;
        }
        
        for(int i=1; i<N+1; i++) {
            if(i != judge && toJudge[i] == 0) return -1; // if someone doesn't trust judge
        }
        
        return judge;
    }
};