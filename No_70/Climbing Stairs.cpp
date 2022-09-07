class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int pre = 1, cur = 2;
        for(int i=3; i<=n; i++) {
            int tmp = cur;
            cur = pre + cur;
            pre = tmp;
        }
        return cur;
    }
};