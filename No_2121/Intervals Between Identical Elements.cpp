class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long>> hmap; // {previous sum, pre position, count}
        int n = arr.size();
        vector<long long> ret(n);
        for(int i=0; i<n; i++) { // previous sum from left to right
            if(hmap[arr[i]].size() == 0) {
                hmap[arr[i]].push_back(0);
                hmap[arr[i]].push_back(0);
                hmap[arr[i]].push_back(0);
            }
            hmap[arr[i]][0] += (i-hmap[arr[i]][1])*hmap[arr[i]][2]; 
            ret[i] += hmap[arr[i]][0];
            hmap[arr[i]][1] = i;
            hmap[arr[i]][2]++;
        }
        
        hmap.clear();
        
        for(int i=n-1; i>=0; i--) { // previous sum from right to left
            if(hmap[arr[i]].size() == 0) {
                hmap[arr[i]].push_back(0);
                hmap[arr[i]].push_back(0);
                hmap[arr[i]].push_back(0);
            }
            hmap[arr[i]][0] += (hmap[arr[i]][1]-i)*hmap[arr[i]][2]; 
            ret[i] += hmap[arr[i]][0];
            hmap[arr[i]][1] = i;
            hmap[arr[i]][2]++;
        }
        
        return ret;
    }
};