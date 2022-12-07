class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }

        vector<int> ret(m);
        for(int i=0; i<m; i++) {
            int j=0;
            for(;j<n; j++) {
                if(nums[j] > queries[i])
                    break;
            }
            ret[i] = j;
        }

        return ret;
    }
};