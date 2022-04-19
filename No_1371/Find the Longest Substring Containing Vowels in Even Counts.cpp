class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> hmap;
        hmap[0] = -1;
        int ret = 0;
        int mask = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {         
                int shift = s[i] - 'a';
                mask ^= (1 << shift);
            }
            if(hmap.find(mask) != hmap.end()) {
                ret = max(ret, i-hmap[mask]);
            } else {
                hmap[mask] = i;
            }
        }
        return ret;
    }
    
    
};