class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ret = 0;
        for(int i=1; i<arr.size(); i++) {
            arr[i] += arr[i-1];
        }
        
        for(int i=0; i<arr.size(); i++) {
            for(int j=i; j<arr.size(); j+=2) {
                if(i == 0) {
                    ret += arr[j];
                } else {
                    ret += (arr[j] - arr[i-1]);
                }
            }
        }
        
        return ret;
    }
};