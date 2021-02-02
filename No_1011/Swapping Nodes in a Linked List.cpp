class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for(int i = 0; i<weights.size(); i++) {
            right += weights[i];
        }
        
        while(left < right) { // binary search
            if(determine(weights, D, (left + right)/2)) {
                right = (left + right)/2;
            }else {
                left = (left + right)/2 + 1;
            }
        }
        
        return right;
    }
    
    bool determine(vector<int>& weights, int D, int capacity) {
        int tmp = capacity;
        for(int i=0; i<weights.size(); i++) {
            if(capacity < weights[i]) return false; // if impossible work
            if(D > 0) { // if within the deadline
                if(weights[i] <= tmp) {
                    tmp -= weights[i];
                    
                }else {
                    D--;
                    tmp = capacity;
                    tmp -= weights[i];
                }
            }else {
                return false;
            }
            
        }
        
        if(D > 0) return true;
        return false;
    }
        
};