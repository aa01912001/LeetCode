class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if (sum % 4 != 0) return false;
        
        int target = sum / 4;
        vector<int> group(4, 0);
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        return findPossibleGroup(group, matchsticks, target, 0);
    }
    
    bool findPossibleGroup(vector<int>& group, vector<int>& matchsticks, int target, int index) {
        if (index >= matchsticks.size()) {
            for (int num : group) {
                if (num != target)
                    return false;
            }
            return true;
        }
        
        for (int i=0; i<4; i++) {
            if (group[i]+matchsticks[index] <= target) {
                group[i] += matchsticks[index];
                if (findPossibleGroup(group, matchsticks, target, index+1)) 
                    return true;
                group[i] -= matchsticks[index];
            }
        }
        
        return false;
    }
};