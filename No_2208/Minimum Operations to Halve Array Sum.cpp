class Solution {
public:
    int halveArray(vector<int>& nums) {
        double target = 0;
        priority_queue<double> maxHeap;
        for (int i=0; i<nums.size(); i++) {
            target += nums[i];
            maxHeap.push(nums[i]);
        }
        
        target /= 2;
        double sum = 0;
        int ret = 0;
        while (sum < target) {
            double t = maxHeap.top(); maxHeap.pop();
            t /= 2;
            sum += t;
            maxHeap.push(t);
            ret++;
        }
        
        return ret;
    }
};