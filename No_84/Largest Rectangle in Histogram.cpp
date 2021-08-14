class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ret = 0;
        s.push(-1);
        heights.push_back(0);
        for(int i=0; i<heights.size(); i++) {
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                int cur = s.top(); s.pop();
                ret = max(ret, heights[cur]*(i-s.top()-1));
            }
            s.push(i);
        }
        
        return ret;
        
    }
};