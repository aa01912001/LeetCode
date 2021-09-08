class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, long>> s; // hold the index with increasing value
        long int ret = 0;
        
        for(int i=0; i<arr.size(); i++) {
            while(!s.empty() && arr[i] <= arr[s.top().first]) { // pop the item in stack which its value is more than or equal to arr[i]
                s.pop();
            }
            if(s.empty()) {
                s.push({i, arr[i]*(i+1)});            
            } else {
                s.push({i, arr[i]*(i-s.top().first) + s.top().second});
            }
            
            ret += s.top().second;
        }
        
        return ret % 1000000007;
    }
};