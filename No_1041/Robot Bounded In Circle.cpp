class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        int direction = 0, x = 0, y = 0;
        
        for (int i = 0; i < instructions.length(); i++) {
            switch (instructions[i]) {
            case 'L':
                direction = (direction + 1 + 4) % 4;
                break;
            case 'R':
                direction = (direction - 1 + 4) % 4;
                break;
            case 'G':
                x += dir[direction][0];
                y += dir[direction][1];
            }
        }
        
        return (x == 0 && y == 0) || direction != 0;
    }
};