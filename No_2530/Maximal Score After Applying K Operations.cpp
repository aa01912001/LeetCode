class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;
        for(int num : nums) {
            maxHeap.push(num);
        }
        
        long long ret = 0;
        while (k--) {
            int top = maxHeap.top(); maxHeap.pop();
            ret += top;
            maxHeap.push(ceil(top / 3.));
        }
        
        return ret;
    }
};