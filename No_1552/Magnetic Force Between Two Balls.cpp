class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n-1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(position, m, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
    
    bool isPossible(vector<int>& position, int m, int mid) {
        int ballCount = 1, preBallPosition = 0;
        for(int i=1; i<position.size(); i++) {
            if(position[i] - position[preBallPosition] >= mid) {
                ballCount++;
                preBallPosition = i;
            }
        }
        if(ballCount >= m)
            return true;
        return false;
    }
};