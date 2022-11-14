class Solution {
public:
    const int mod = 1e9 + 7;
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> comb(n+1, vector<long long>(n+1));
        for(int i=0; i<=n; i++){
            comb[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
            }
        }
        
        return solve(nums, comb) - 1;
    }
    
    long long solve(vector<int>& nums, vector<vector<long long>>& comb) {
        if(nums.size() <= 2) return 1;
        vector<int> less, greater;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[0]) {
                less.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }
    
        return ((comb[nums.size()-1][less.size()] * solve(less, comb)) % mod * solve(greater, comb)) % mod;
    }
};