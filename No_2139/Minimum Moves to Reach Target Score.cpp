class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while(maxDoubles != 0 && target != 1) {
            if(target % 2 == 1) ret++;
            target = target / 2;
            maxDoubles--;
            ret++;
        }
        
        return target == 1 ? ret : ret + target - 1;
    }
};