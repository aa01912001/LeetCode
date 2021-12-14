class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> dpFirst(n); // dpFirst[i]: to store the maximum sum of subarray with length firstLen from nums[0] to nums[i-1]
        vector<int> dpSecond(n); // dpSecond[i]: to store the maximum sum of subarray with length secondLen from nums[0] to nums[i-1]
        int sum = 0;
        for(int i=0; i<n; i++) { // build dpFirst
            sum += nums[i];
            if(i >= firstLen) {
                dpFirst[i] = max(dpFirst[i-1], sum-nums[i]);
                sum = sum-nums[i-firstLen];
            }
        }
        
        sum = 0;
        for(int i=0; i<n; i++) { // build dpSecond
            sum += nums[i];
            if(i >= secondLen) {
                dpSecond[i] = max(dpSecond[i-1], sum-nums[i]);
                sum = sum-nums[i-secondLen];
            }
        }
        
        int ret = 0;
        sum = 0;
        vector<int> preSum(n);
        for(int i=0; i<n; i++) { // DP for considering every nums[i] may belong to subarray with length firstLen or secondLen
            sum += nums[i];
            preSum[i] = sum;
            if(i >= firstLen+secondLen-1) {
                ret = max(ret, sum-preSum[i-firstLen]+dpSecond[i-firstLen+1]);
                ret = max(ret, sum-preSum[i-secondLen]+dpFirst[i-secondLen+1]);
            }
        }
        return ret;
    }
};