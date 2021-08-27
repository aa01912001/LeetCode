class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hset, inter;
        vector<int> ret;
        
        for(int i=0; i<nums1.size(); i++) {
            hset.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++) {
            if(hset.find(nums2[i]) != hset.end()) inter.insert(nums2[i]);
        }
        
        for(auto t : inter) {
            ret.push_back(t);
        }
        
        return ret;
    }
};