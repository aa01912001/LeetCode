class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > min_heap;
        int n = nums.size();
        for(int i=0; i<n;i++) {
            min_heap.push(nums[i]);
        }
        
        vector<int> ret(n, 0);
        for(int i=0; i<n; i++) {
            ret[i] = min_heap.top();
            min_heap.pop();
        }
        
        return ret;
    }
};