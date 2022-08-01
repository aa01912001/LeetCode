class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sumOfWindow = accumulate(nums.begin(), nums.begin()+k, 0);
        int start = 0, end = k-1;
        double ret = INT_MIN;
        while(end < nums.size()-1) {
            ret = max(ret, sumOfWindow);
            sumOfWindow -= nums[start++];
            sumOfWindow += nums[++end];
        }
        ret = max(ret, sumOfWindow);
        return ret/k;
    }
};