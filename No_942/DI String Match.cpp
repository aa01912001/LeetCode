class Solution {
public:
    vector<int> diStringMatch(string S) {
        int L = 0, H = S.length();
        vector<int> ret(H+1);
        ret[0] = S[0] == 'I' ? L++ : H--;
        
        int i;
        for(i=1; i < S.length(); i++) {
            if(S[i] == 'I') ret[i] = L++;
            else ret[i] = H--;
        }
        
        ret[i] = L;
        
        return ret;
    }
};