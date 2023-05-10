class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        
        for (int i=0; i<k; i++) {
            int t = minHeap.top();
            minHeap.pop();
            minHeap.push(t+1);
        }
        
        long long ret = 1;
        while (!minHeap.empty()) {
            int t = minHeap.top();
            minHeap.pop();
            ret = (ret * t) % MOD;
        }
        
        return ret;
    }
};