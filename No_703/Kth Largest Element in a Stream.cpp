class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int th;
public:
    KthLargest(int k, vector<int>& nums) {
        th = k;
        for(int i=0; i<nums.size(); i++) { 
            minHeap.push(nums[i]);
            if(minHeap.size() > k) minHeap.pop(); // only store kth largest numbers.
        }
    }
    
    int add(int val) {
        if(minHeap.size() < th || val > minHeap.top()) {
            minHeap.push(val);
            if(minHeap.size() > th) minHeap.pop(); // pop (k+1)th largest number.
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */