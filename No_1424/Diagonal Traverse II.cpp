class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0;j <nums[i].size(); j++) {
                vector<int> tmp(3);
                minHeap.push({i+j, j, nums[i][j]});
            }
        }
        
        vector<int> ret;
        while(!minHeap.empty()) {
            ret.push_back(minHeap.top()[2]);
            minHeap.pop();
        }
        return ret;
        
    }
};