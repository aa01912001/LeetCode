class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<float, int> hmap;
        int n = changed.size();
        vector<int> ret;
        
        if (n % 2 == 1) return {};
        
        for (int i=0; i<n; i++) {
            hmap[changed[i]]++;
        }
        
        sort(changed.begin(), changed.end());
        for (int i=n-1; i>=0; i--) {
            int num = changed[i];
            if (hmap.find(num) == hmap.end()) {
                // num has been removed from hmap
                continue;
            } else {
                float target = num / 2.;
                if (hmap.find(target) == hmap.end()) {
                    return {};
                } else {
                    hmap[num]--;
                    if (hmap[num] == 0) hmap.erase(num);
                    hmap[target]--;
                    if (hmap[target] == 0) hmap.erase(target);
                    ret.push_back(target);
                }
            }
        }
        
        return ret;
    }
};