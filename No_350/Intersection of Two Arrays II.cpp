class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hmap1, hmap2;
        for(int i=0; i<nums1.size(); i++) {
            hmap1[nums1[i]]++;
        }
        
        for(int i=0; i<nums2.size(); i++) {
            hmap2[nums2[i]]++;
        }
        
        vector<int> ret;
        for(auto t : hmap1) {
            if(hmap2.find(t.first) != hmap2.end()) {
                int count = min(t.second, hmap2[t.first]);
                while(count--) {
                    ret.push_back(t.first);
                }
            }
        }
        
        return ret;
    }
};