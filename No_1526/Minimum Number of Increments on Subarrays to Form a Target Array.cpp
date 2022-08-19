class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ret = target[0];
        for(int i=1; i<target.size(); i++) {
            if(target[i] > target[i-1]) ret += target[i] - target[i-1];
        }
        return ret;
    }
};