class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comparator = [](const string& s1, const string& s2){
            if(s1.length() == s2.length()) {
                return s1 > s2;
            }
            return s1.length() > s2.length();
        };
        
        priority_queue<string, vector<string>, decltype(comparator)> minHeap(comparator);
        
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(minHeap.size() != k ) {
                minHeap.push(nums[i]);
            } else {
                minHeap.push(nums[i]);
                minHeap.pop();
            }
        }
    
        return minHeap.top();
    }
};


