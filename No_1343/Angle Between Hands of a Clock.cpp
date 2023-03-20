class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, right = 0, n = arr.size(), ret = 0;
        float sum = arr[0];
        while(right < n) {
            if(right - left + 1 < k) {
                sum += arr[++right];
            } else {
                if(sum / k >= threshold) ret++;
                sum -= arr[left++];
                if(++right == n) break;
                sum += arr[right];
            }
        }
        
        return ret;
    }
};