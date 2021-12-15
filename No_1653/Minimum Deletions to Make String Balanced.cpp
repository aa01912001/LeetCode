class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int dp = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'b') {
                b_count++;
            } else {
                dp = min(dp+1, b_count);
            }
        }
        
        return dp;
    }
};