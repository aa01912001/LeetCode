class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int lastY = coordinates[1][1] - coordinates[0][1];
        int lastX = coordinates[1][0] - coordinates[0][0];
        for(int i=2; i<coordinates.size(); i++) {
            int currY = coordinates[i][1] - coordinates[1][1];
            int currX = coordinates[i][0] - coordinates[1][0];
            if(lastX*currY != lastY*currX) return false;
        }
        
        return true;
    }
};