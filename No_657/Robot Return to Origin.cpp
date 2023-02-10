class Solution {
public:
    bool judgeCircle(string moves) {
        int xMove = 0, yMove = 0;
        for(char c : moves) {
            switch(c) {
            case 'L':
                xMove--;
                break;
            case 'R':
                xMove++;
                break;
            case 'U':
                yMove++;
                break;
            case 'D':
                yMove--;
                break;
            }
        }
        return !xMove && !yMove;
    }
};