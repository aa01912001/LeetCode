class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k-(arr[0]-1) <= 0) {
            return k;
        }
        
        k = k - (arr[0]-1);
        for(int i=1; i<arr.size(); i++) {
            int gap = arr[i]-arr[i-1]-1;
            k -= gap;
            if(k <= 0) return arr[i-1]+k+gap;
        }
        return arr[arr.size()-1] + k;
    }
};