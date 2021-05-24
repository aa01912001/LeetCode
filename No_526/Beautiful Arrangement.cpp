class Solution {
public:
    int countArrangement(int n) {
        int ret = 0;
        vector<int> arr(n+1, 0);
        for(int i=1; i<arr.size(); i++) {
            arr[i] = i;
        }
        perm(1, arr, ret);
        return ret;
    }
    
    void perm(int start, vector<int>& arr, int& ret) { // traverse all permutation from arr[1] ~ arr[n]
        if(start == arr.size()-1) {
            if((arr.size()-1)%arr[start] == 0 || arr[start]%(arr.size()-1) == 0) {
                ret++;
                return;
            }
        }
        
        for(int i=start; i<arr.size(); i++) {
            swap(arr, i, start);
            if(arr[start]%start != 0 && start%arr[start] != 0) {
                swap(arr, i, start);
                continue;
            }
            
            perm(start+1, arr, ret);
            swap(arr, i, start);
        }
        
        return;
    }
    
    void swap(vector<int>& arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        return;
    }
};