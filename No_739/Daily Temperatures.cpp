class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk; // {num, index}
        vector<int> ret;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int num = temperatures[i];
            while (!stk.empty() && num >= stk.top().first)
                stk.pop();
            
            if (stk.empty()) {
                ret.push_back(0);
            } else {
                ret.push_back(stk.top().second - i);
            }
            
            stk.push({num, i});
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};