class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ret(n);
        
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 ==0)
                sum += nums[i];
        }
        
        for (int i=0; i<n; i++) {
            int origin = nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            if (nums[queries[i][1]] % 2 == 0) {
                if (abs(origin % 2) == 1) {
                    sum += nums[queries[i][1]];
                } else {
                    sum += queries[i][0];
                }
            } else {
                if (origin % 2 == 0) {
                    sum -= origin;
                }
            }
            
            ret[i] = sum;
        }
                                
        return ret;
    }
};