class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        int l, r;
        for(l = 1; l<arr.size(); l++) {
            if(arr[l] <= arr[l-1]) {
                l = l - 1 ;
                break;
            }
        }
        
        for(r = arr.size()-2; r>=0; r--) {
            if(arr[r] <= arr[r+1]) {
                r = r + 1 ;
                break;
            }
        }
        
        return l == r;
    }
};