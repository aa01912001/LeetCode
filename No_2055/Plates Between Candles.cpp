class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> nextLeftCandle(n);
        vector<int> nextRightCandle(n);
        vector<int> LeftNumOfPlate(n);
        
        nextRightCandle[n-1] = n - 1;
        if(s[0] == '*') LeftNumOfPlate[0] = 1;
        
        
        for(int i=1; i<n; i++) {
            if(s[i] == '|') {
                nextLeftCandle[i] = i;
                LeftNumOfPlate[i] = LeftNumOfPlate[i-1];
            } else {
                nextLeftCandle[i] = nextLeftCandle[i-1];
                LeftNumOfPlate[i] = LeftNumOfPlate[i-1] + 1;
            }
        }
        
        for(int i=n-2; i>=0; i--) {
            if(s[i] == '|') {
                nextRightCandle[i] = i;
            } else {
                nextRightCandle[i] = nextRightCandle[i+1];
            }
        }
        
        vector<int> ret(queries.size());
        for(int i=0; i<queries.size(); i++) {
            cout << nextRightCandle[queries[i][0]] << endl;
            if(nextRightCandle[queries[i][0]] < nextLeftCandle[queries[i][1]]) {
                ret[i] = LeftNumOfPlate[nextLeftCandle[queries[i][1]]] - LeftNumOfPlate[nextRightCandle[queries[i][0]]];
            }
        }
       
        return ret;
    }
};