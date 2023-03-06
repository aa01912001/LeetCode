class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        vector<vector<int>> ret;
        
        for(int i=0; i<min(n1, k); i++) {
            for(int j=0; j<min(n2, k); j++) {
                int sum = nums1[i] + nums2[j];
                if(maxHeap.size() < k) {
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                } else if(maxHeap.top().first > sum) {
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }
        
        while(!maxHeap.empty()) {
            ret.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        
        return ret;
    }
};