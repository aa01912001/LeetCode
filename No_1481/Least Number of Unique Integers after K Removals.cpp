class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hmap;
        for(int i=0; i<arr.size(); i++) {
            hmap[arr[i]]++;
        }
        
        vector<pair<int, int> > arrWithCount;
        for(int i=0; i<arr.size(); i++) {
            arrWithCount.push_back({hmap[arr[i]], arr[i]});
        }
        
        sort(arrWithCount.begin(), arrWithCount.end());
        
        unordered_set<int> hset;
        for(int i=k; i<arrWithCount.size(); i++) {
            hset.insert(arrWithCount[i].second);

        }
        return hset.size();
    }
};