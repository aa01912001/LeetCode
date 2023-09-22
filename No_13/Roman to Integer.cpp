class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> hmap{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && hmap[s[i]] < hmap[s[i+1]]) {
                ret -= hmap[s[i]];
            } else {
                ret += hmap[s[i]];
            }
        }
        
        return ret;
    }
};