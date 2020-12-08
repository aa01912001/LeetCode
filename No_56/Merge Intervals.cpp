class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //  sort intervals
        vector<vector<int>> ret;
        int start = intervals[0][0]; 
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= end) { // next start is less equal than previous end 
                end = max(end ,intervals[i][1]);
            }else { // next start is greater than previous end
                ret.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        ret.push_back({start, end});
        
        
        return ret;
    }
};