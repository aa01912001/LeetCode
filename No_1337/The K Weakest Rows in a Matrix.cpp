class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0; i<mat.size(); i++) {
            int count = 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 1) count++;
            }
            minHeap.push({count, i});
        }
        
        vector<int> ret;
        while(k--) {
            ret.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ret;
    }
};