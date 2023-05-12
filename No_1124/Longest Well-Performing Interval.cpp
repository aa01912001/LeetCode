class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> hmap;
        int preSum = 0;
        int ret = 0;
        for (int i=0; i<hours.size(); i++) {
            preSum += hours[i] > 8 ? 1 : -1;
            if (preSum > 0) {
                ret = i + 1;
            } else {
                if (!hmap.count(preSum)) {
                    hmap[preSum] = i;
                }
                
                if (hmap.count(preSum-1)) {
                    ret = max(ret, i-hmap[preSum-1]);
                }
            }
        }
        
        return ret;
    }
};