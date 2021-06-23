class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ret(n+1, first);
        for(int i=0; i<n; i++) {
            ret[i+1] = encoded[i] ^ ret[i];
        }
        
        return ret;
    }
};