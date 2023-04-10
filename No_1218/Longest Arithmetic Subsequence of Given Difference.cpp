class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hmap;
        int n = arr.size(), ret = 1;
        for (int i=0; i<n; i++) {
            int target = arr[i] - difference;
            if (hmap.find(target) == hmap.end()) {
                hmap[arr[i]] = 1;
            } else {
                hmap[arr[i]] = hmap[target] + 1;
                ret = max(ret, hmap[arr[i]]);
            }
        }
        return ret;
    }
};