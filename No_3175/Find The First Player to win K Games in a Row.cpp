class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int remaining = k, ret = 0, n = skills.size();

        for (int i = 1; i < n; i++) {
            if (skills[ret] > skills[i]) {
                remaining--;
            } else {
                ret = i;
                remaining = k - 1;
            }

            if (remaining == 0)
                return ret;
        }

        return ret;
    }
};