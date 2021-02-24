class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0;
        int ret = 0;
        for(int i=satisfaction.size()-1; i>=0; i--) {
            ret = max(ret, satisfaction[i] + ret + sum);
            sum += satisfaction[i];
        }
        
        return ret;
    }
};