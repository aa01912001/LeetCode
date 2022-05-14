class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ret(n, true);
        for(int i=0; i<n; i++) {
            vector<int> t(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(t.begin(), t.end());
            int gap = t[1] - t[0];
            for(int j=2; j<t.size(); j++) {
                if(t[j]-t[j-1] != gap) ret[i] = false;
            }
        }
        return ret;
    }
};