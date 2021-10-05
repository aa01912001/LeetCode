class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n_remove=0;
        for(int i=0; i<intervals.size();) {
            if(i == intervals.size()) break;
            int j = i+1;
            while(j<intervals.size() && intervals[i][1] >= intervals[j][1]) {
                n_remove++;
                j++;
            }
            i = j;
        }
        
        return intervals.size()-n_remove;
    }
    
    static bool compare(vector<int> a, vector<int> b){
        if(a[0] < b[0]) {
            return true;
        } else if(a[0] == b[0] && a[1] >= b[1]) {
            return true;
        }
        
        return false;
    }
};