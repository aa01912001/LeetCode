class Solution {
public:
    int beautySum(string s) {
        int ret = 0;
        for(int i=0; i<s.length(); i++) {
            vector<int> count(26);
            int mx = INT_MIN;
            for(int j=i; j<s.length(); j++) {
                int index = s[j] - 'a';
                count[index]++;
                mx = max(mx, count[index]);
                int mn = INT_MAX;
                for(int k=0; k<26; k++) {
                    if(count[k] != 0) 
                        mn = min(mn, count[k]);
                }
                ret += mx - mn;
                
            }
        }
        
        return ret;
    }
};