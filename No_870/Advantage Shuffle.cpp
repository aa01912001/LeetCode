class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<int> ret;
        for(int i=0; i<nums2.size(); i++) {
            for(int j=0; j<nums1.size(); j++) {
                if(nums1[j] > nums2[i]) {
                    ret.push_back(nums1[j]);
                    nums1.erase(nums1.begin()+j);
                    break;
                }
            }
            if(ret.size() != i+1) {
                ret.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        
        return ret;
    }
};