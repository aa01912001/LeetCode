class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n+1, INT_MAX);
        int ret = INT_MAX;

        int left = 0, right = 0, sum = arr[0];
        int curMinLen = INT_MAX;
        while(1) {
            if(sum == target) {
                curMinLen = min(curMinLen, right-left+1);
                if(dp[left] != INT_MAX)
                    ret = min(ret, dp[left]+right-left+1);
            }
            dp[right+1] = curMinLen;
            if(sum > target && left != right) {
                sum -= arr[left];
                left++;
                if(left == n) break;
            } else {
                right++;
                if(right == n) break;
                sum += arr[right];
            }
        }
        
        return ret == INT_MAX ? -1 : ret;
    }
};