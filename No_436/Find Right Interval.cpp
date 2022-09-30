class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ret(n, -1);
        unordered_map<int, int> hmap; // to record the mapping of start and index
        
        for(int i=0; i<n; i++) {
            hmap[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end());     
        for(int i=0; i<n; i++) {
            int targetIndex = binarySearch(intervals, intervals[i][1]);
            if(targetIndex != n) {
                ret[hmap[intervals[i][0]]] = hmap[intervals[targetIndex][0]];
            }
        }
        
        return ret;
    }
    
    int binarySearch(vector<vector<int>>& intervals, int target) {
        int i = 0, j = intervals.size();
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(intervals[mid][0] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return j;
    }
};