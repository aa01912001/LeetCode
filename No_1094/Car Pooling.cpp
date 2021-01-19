class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> loc(1001, 0);
        for(int i=0; i<trips.size(); i++) { // record the num of passengers
            loc[trips[i][1]] += trips[i][0];
            loc[trips[i][2]] -= trips[i][0];
        }
        
        int cur = 0;
        for(int i=1; i<=1000; i++) { // calculate the number of passengers all the way
            cur += loc[i];
            if(cur > capacity) return false;
        }
        
        return true;
    }
};