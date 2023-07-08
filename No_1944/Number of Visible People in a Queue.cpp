class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> ret(n);
        
        stk.push(0);
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && heights[i] > heights[stk.top()]) {
                    ret[stk.top()]++;
                    stk.pop();
            }
            
            if (!stk.empty()) ret[stk.top()]++;
                
            stk.push(i);
        }
        
        return ret;
    }
};