class Solution {
public:
    int countSubstrings(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<vector<int>> same(n1, vector<int>(n2)), diff(n1, vector<int>(n2));
        int ret  = 0;
        
        for(int i=0; i<n1; i++) {
            if(t[0] == s[i]) {
                same[i][0] = 1;
            } else {
                diff[i][0] = 1;
                ret += 1;
            }
        }
        
        for(int i=1; i<n2; i++) {
            if(s[0] == t[i]) {
                same[0][i] = 1;
            } else {
                diff[0][i] = 1;
                ret += 1;
            }
        }
        
        for(int i=1; i<n1; i++) {
            for(int j=1; j<n2; j++) {
                if(s[i] == t[j]) {
                    same[i][j] = 1 + same[i-1][j-1];
                    diff[i][j] = diff[i-1][j-1];
                } else {
                    same[i][j] = 0;
                    diff[i][j] = 1 + same[i-1][j-1];
                }
                ret += diff[i][j];
            }
        }
        
        return ret;
        
    }
};