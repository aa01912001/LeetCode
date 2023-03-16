class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<float, int> hmap;
        int ret = 0;
        
        for(int square : nums) {
            int num = sqrt(square);
            if(num*num == square) {
                ret = max(ret, hmap[num]+1);
                hmap[square] = hmap[num] + 1;
            } else {
                hmap[square] = 1;
            }
        }
        
        return ret < 2 ? -1 : ret;
    }
};