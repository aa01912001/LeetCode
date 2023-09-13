class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        
        backtracking(0, candidates, target, cur, ret);
            
        return ret;
    }
    
    void backtracking(int index, vector<int>& candidates, int target, vector<int> &cur, vector<vector<int>> &ret) {
        if (target == 0) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtracking(i, candidates, target-candidates[i], cur, ret);
                cur.pop_back();
            } else {
                break;
            }
        }
        
        return;
    }
};