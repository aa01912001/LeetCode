class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n <= 3) return stones[n-1] - stones[0];
        
        int ret = 0;
        for(int i=0; i<stones.size(); i++) {
            if(i+2 < n) ret = max(ret, stones[i+2]-stones[i]);
            if(i+3 < n) ret = max(ret, stones[i+3]-stones[i+1]);
        }
        return ret;
    }
};