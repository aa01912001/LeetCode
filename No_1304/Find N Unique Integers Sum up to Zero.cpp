class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        int sum = 0;
        for(int i=1; i<=n-1; i++) {
            ret.push_back(i);
            sum += i;
        }
        
        ret.push_back(-sum);
        return ret;
    }
};