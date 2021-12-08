class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix(arr.size()+1);
        prefix[1] = arr[0];
        for(int i=1; i<arr.size(); i++) {
            prefix[i+1] = prefix[i] ^ arr[i];
        }
        
        int ret = 0;
        for(int i=1; i<prefix.size(); i++) {
            for(int j=0; j<=i-2; j++) {
                if((prefix[i]^prefix[j]) == 0) {
                    ret += i - j - 1;
                }
            }
        }
        
        return ret;
    }
};