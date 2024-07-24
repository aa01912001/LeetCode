class Solution {
public:
    int minimumLength(string s) {
        int ret = 0;
        unordered_map<char, int> hmap;
        
        for (char c : s) {
            hmap[c]++;
        }
        
        for (auto t : hmap) {
            if (t.second % 2 == 1)
                ret += 1;
            else
                ret += 2;
        }
        
        return ret;
    }
};