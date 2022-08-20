class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>> pq; // {tail value of ith list, ith list, current index of ith list}
        vector<int> ret;
        int minValue = INT_MAX;
        
        for(int i=0; i<nums.size(); i++) {
            // push last value of each list into max heap
            minValue = min(minValue, nums[i][nums[i].size()-1]);
            pq.push({nums[i][nums[i].size()-1], i, (int)(nums[i].size()-1)});
        }
        ret = {minValue, pq.top()[0]};   
        
        while(1) {
            int maxValue =pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            if(j == 0) break;
            minValue = min(minValue, nums[i][j-1]);
            pq.push({nums[i][j-1], i, j-1});
            pq.pop();
            if(pq.top()[0]-minValue <= ret[1]-ret[0]) ret = {minValue, pq.top()[0]};
        }
        return ret;
    }
};