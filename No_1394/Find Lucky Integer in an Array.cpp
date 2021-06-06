class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hmap;
        for(int i=0; i<arr.size(); i++) {
            hmap[arr[i]]++;
        }        
        
        int ret = -1;
        for(auto &t : hmap) {
            if(t.first == t.second) {
                ret = max(ret, t.first);
            }
        }
        
        return ret;
    }
};