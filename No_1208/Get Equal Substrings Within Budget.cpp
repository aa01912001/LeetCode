class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> prefixSumOfCost(n+1);
        prefixSumOfCost[1] = abs(s[0]-t[0]);
        for(int i=1; i<n; i++) {
            prefixSumOfCost[i+1] = prefixSumOfCost[i] + abs(s[i]-t[i]);
        }
        
        int ret = 0;
        int i = 0, j = 0;
        while(j <= n) {
            if(prefixSumOfCost[j]-prefixSumOfCost[i] <= maxCost) {
                ret = max(ret, j-i);  
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
};