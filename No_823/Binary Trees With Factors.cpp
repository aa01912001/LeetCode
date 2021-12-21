class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long int> dp;
        int ret = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) { // arr[i] to be root
            for(int j=0; j<i; j++) {
                if(arr[i]%arr[j] == 0) {
                    int d = arr[i] / arr[j];
                    if(dp.find(d) != dp.end()){ // if we can find two nums a and b from arr[0] ~ arr[i-1] which a*b equals arr[i]
                        dp[arr[i]] += (dp[arr[j]] * dp[d]) % 1000000007;   
                    }
                }
            }
            dp[arr[i]]++;
            ret = (ret + dp[arr[i]]) % 1000000007;
        }
        
        return ret;
    }
};