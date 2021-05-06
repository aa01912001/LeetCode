class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for(int i=0; i<nums.size(); i++) {
            q.push(nums[i]);
        }
        
        int maxNum(q.top()); q.pop();
        
        return (maxNum-1)*(q.top()-1); 
    }
};