class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) { 
        vector<int> iXor(arr.size()+1), ret(queries.size());
        iXor[0] = 0;
        for(int i=1; i<=arr.size(); i++) { // calculate the XOR from arr[0] to arr[i];
            iXor[i]= arr[i-1]^iXor[i-1];
            
        }
        
        for(int i=0; i<queries.size(); i++) {
            ret[i] = iXor[queries[i][1]+1]^iXor[queries[i][0]];
        }
        
        return ret;
    }
};