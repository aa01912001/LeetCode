class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> diGraph(n, vector<int>());
        for(int i=0; i<n; i++) { // build directed graph
            if(manager[i] != -1) {
                diGraph[manager[i]].push_back(i);
            }
        }
        
        int ret = 0;
        DFS(headID, diGraph, informTime, 0, ret);
        return ret;
    }
    
    void DFS(int root, vector<vector<int>> &diGraph, vector<int> & informTime, int time, int &ret) {
        time += informTime[root];
        ret = max(ret, time);
        for(int i=0; i<diGraph[root].size(); i++) { // for each subordinate
            DFS(diGraph[root][i], diGraph, informTime, time, ret);
        }
    }
};