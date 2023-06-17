class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int pre = -1, ret = 0;
        for (int i=0; i<n; i++) {
            if (seats[i] != 0) {
                if (pre == -1) {
                    ret = i;
                } else {
                    ret = max(ret, (i-pre)/2);
                }
                pre = i;
            }
        }
        
        ret = max(ret, n-pre-1);
        
        return ret;
    }
};