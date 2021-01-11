class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i=0; i<accounts.size(); i++) {
            int tmp = 0;
            for(int j=0; j<accounts[i].size(); j++) {
                tmp += accounts[i][j];
            }
            if(max < tmp) max = tmp; 
        }
        
        return max;
    }
};