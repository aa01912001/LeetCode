class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0, n = rating.size();
        
        for (int i = 0; i < n; i++) {
            int l = 0, r = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i])
                    l++;
            }
            for (int k = i + 1; k < n; k++) {
                if (rating[k] > rating[i])
                    r++;
            }
            
            ret += l * r + (i - l) * (n - i - 1 - r);
        }
        
        return ret;
    }
};