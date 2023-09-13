class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hmap; // {alpha, count}
        int n = s.length(), ret = 0;
        
        int left = 0;
        for (int i = 0; i < n; i++) {
           if (++hmap[s[i]] == 1) {
               ret = max(ret, i - left + 1);
           } else {
               while (hmap[s[i]] != 1) {
                   hmap[s[left]]--;
                   left++;
               }
           }
        }
        
        return ret;
    }
};