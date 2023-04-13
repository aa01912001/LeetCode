class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        int n =time.size();
        vector<int> count(60);
        for (int i=0; i<n; i++) {
            int mod = time[i] % 60;
            if (mod == 0) {
                ret += count[0];
            } else {
                ret += count[60 - mod];
            }
            count[mod]++;
        }
        
        return ret;
    }
};