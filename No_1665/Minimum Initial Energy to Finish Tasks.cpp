class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> &t1, vector<int> &t2){
            if (t1[1] - t1[0] > t2[1] - t2[0])
                return true;
            return false;
        });
        
        int ret = 0, remaining = 0;
        for (auto &t : tasks) {
            if (remaining < t[1]) {
                ret += t[1] - remaining;
                remaining = t[1];
            }
            remaining -= t[0];
        }
        
        return ret;
    }
};