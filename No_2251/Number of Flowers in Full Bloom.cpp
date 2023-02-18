class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int pSize = persons.size();
        unordered_map<int, int> hmap;
        for(auto flower : flowers) {
            hmap[flower[0]]++;
            hmap[flower[1]+1]--;
        }
        
        vector<vector<int>> v;
        for(auto p : hmap) {
            v.push_back({p.first, p.second}); // {time, diff}
        }
        
        sort(v.begin(), v.end());
        
        vector<vector<int>> p(pSize);
        for(int i=0; i<pSize; i++) {
            p[i] = {persons[i], i}; // {arrival time, index}
        }
        sort(p.begin(), p.end());
        
        int n = v.size();
        int count = 0;
        int j = 0;
        vector<int> ret(pSize);
        for(int i=0; i<pSize; i++) {
            while(j<n && v[j][0] <= p[i][0]) {
                count += v[j][1];
                j++;
            }
            ret[p[i][1]] = count;
        }

        
        return ret;
    }
};