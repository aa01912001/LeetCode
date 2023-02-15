class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            int s = sum(arr, target, mid);
            if(s >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return abs(sum(arr, target, low) - target) < abs(sum(arr, target, low-1) - target) ? low : low - 1;
    }
    
    int sum(vector<int>& arr, int target, int value) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += min(arr[i], value);
        }
        
        return sum;
    }
};