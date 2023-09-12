class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (int i = 0; i < asteroids.size(); i++) {
            if (ret.empty() || asteroids[i] > 0) {
                ret.push_back(asteroids[i]);
            } else {
                while (!ret.empty() && ret.back() > 0 && ret.back() < abs(asteroids[i])) {
                    ret.pop_back();
                }
                    
                if (!ret.empty() && ret.back() > 0 && ret.back() == abs(asteroids[i])) {
                    ret.pop_back();
                } else if (ret.empty() || ret.back() < 0) {
                    ret.push_back(asteroids[i]);
                }
            }
        }
        
        return ret;
    }
};