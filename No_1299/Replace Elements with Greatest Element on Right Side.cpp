class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int tmp = arr[n-1];
        arr[n-1] = -1;
        for(int i=n-2; i>=0; i--) {
            int m = tmp;
            tmp = max(tmp, arr[i]);
            arr[i] = m;
        }
        
        return arr;
    };
};