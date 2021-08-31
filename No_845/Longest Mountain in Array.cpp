class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        vector<int> leftDP(len), rightDP(len);
        for(int i=1; i<len; i++) {
            if(arr[i] > arr[i-1]) {
                leftDP[i] += leftDP[i-1]+1;
            }
        }
        
        for(int i=len-2; i>=0; i--) {
            if(arr[i] > arr[i+1]) {
                rightDP[i] += rightDP[i+1]+1;
            }
        }
        
        int ret = 0;
        for(int i=0; i<len; i++) {
            if(leftDP[i] != 0 && rightDP[i] != 0) {
                ret = max(ret, leftDP[i]+rightDP[i]+1);    
            }
        }
        
        return ret;
    }
};